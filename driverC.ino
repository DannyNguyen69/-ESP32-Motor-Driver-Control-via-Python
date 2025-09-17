#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "DUY";
const char* password = "12345678";

/// note 3 gạch để không bị nói là AI viết

#define IN1 26 
#define IN2 27
#define IN3 14
#define IN4 12
#define ENA 25
#define ENB 33

// Khai báo 2 động cơ motor
typedef struct motor_ctr {
  int in1;
   int in2;
  int en;
  int channel;
} motor_ctr;

WebServer server(80);
motor_ctr motorLeft = {IN1, IN2, ENA, 0};
motor_ctr motorRight = {IN3, IN4, ENB, 1};

// Khởi tạo motor
void motor_init(motor_ctr x) {
  pinMode(x.in1, OUTPUT);
  pinMode(x.in2, OUTPUT);
  ledcSetup(x.channel, 5000, 8);
  ledcAttachPin(x.en, x.channel);
}

void motor_forward(motor_ctr x, int speed) {
  digitalWrite(x.in1, HIGH);
  digitalWrite(x.in2, LOW);
  ledcWrite(x.channel, speed);   // speed: 0-255 (8 bit PWM)
}

void motor_backward(motor_ctr x, int speed) {
  digitalWrite(x.in1, LOW);
  digitalWrite(x.in2, HIGH);
  ledcWrite(x.channel, speed);
}

void motor_stop(motor_ctr x) {
  digitalWrite(x.in1, LOW);
  digitalWrite(x.in2, LOW);
  ledcWrite(x.channel, 0);
}

void handleMotor(){
  // Kiểm tra tham số đầu vào
  if (!server.hasArg("motor") || !server.hasArg("dir") || !server.hasArg("speed")) {
    server.send(400, "text/plain", "Missing parameter");
    return;
  }

  String motor = server.arg("motor");
  String dir = server.arg("dir");
  int speed = server.arg("speed").toInt();

  motor_ctr* target = nullptr;
  
  if (motor == "left") target = &motorLeft;
  else if (motor == "right") target = &motorRight;

  if (target != nullptr) {
    if (dir == "forward") motor_forward(*target, speed);
    else if (dir == "backward") motor_backward(*target, speed);
    else if (dir == "stop") motor_stop(*target);
    server.send(200, "text/plain", "OK");
  } else {
    server.send(400, "text/plain", "deo co motor");
  }
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);
  Serial.println(WiFi.localIP());
  Serial.println("Da ket noi");

  motor_init(motorLeft);
  motor_init(motorRight);

  server.on("/motor", handleMotor);
  server.begin();
}

void loop() {
  server.handleClient();
}