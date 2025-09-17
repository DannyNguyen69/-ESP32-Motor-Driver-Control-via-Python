import requests

ESP_IP = "http://192.168.63.151"  # thay IP esp của bạn

def motor_forward(speed=200):
    requests.get(f"{ESP_IP}/motor", params={"motor": "left", "dir": "forward", "speed": speed})
    requests.get(f"{ESP_IP}/motor", params={"motor": "right", "dir": "forward", "speed": speed})

def motor_backward(speed=200):
    requests.get(f"{ESP_IP}/motor", params={"motor": "left", "dir": "backward", "speed": speed})
    requests.get(f"{ESP_IP}/motor", params={"motor": "right", "dir": "backward", "speed": speed})

def motor_stop():
    requests.get(f"{ESP_IP}/motor", params={"motor": "left", "dir": "stop", "speed": 0})
    requests.get(f"{ESP_IP}/motor", params={"motor": "right", "dir": "backward", "speed": 0})

# Ví dụ

a = int(input("Nhap so:"))

while True:
    if a == 1:
        motor_forward(255)
    elif a == 2:
        motor_backward(255)
    elif a == 3:
        motor_stop()
