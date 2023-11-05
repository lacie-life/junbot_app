# python 3.6

import random
import time
import json
from paho.mqtt import client as mqtt_client

# Broker address
broker = 'localhost'

# Broker port
port = 1883

# Topic publish
topic_state = "robot1/state"
topic_login_userInforesponse = "robot1/login_userInforesponse"
topic_deliver_response = "robot1/deliver_response"

# Topic subscribe
topic_control = "robot1/control"
topic_login_request = "robot1/login_request"
topic_deliver = "robot1/deliver"

# generate client ID with pub prefix randomly
client_id = f'python-mqtt-{random.randint(0, 1000)}'
# username = 'emqx'
# password = 'public'

def connect_mqtt():
    def on_connect(client, userdata, flags, rc):
        if rc == 0:
            print("Connected to MQTT Broker!")
        else:
            print("Failed to connect, return code %d\n", rc)

    client = mqtt_client.Client(client_id)
    
    # Update username and password if it is set by your admin
    client.username_pw_set("Demo", "1")
    client.on_connect = on_connect
    client.connect(broker, port)

    client.subscribe(topic_control)
    client.subscribe(topic_login_request)
    client.subscribe(topic_deliver)

    return client

def on_message(client, userdata, msg):
    print(f"Received `{msg.payload.decode()}` from `{msg.topic}` topic")

def publish(client):

    # default msg
    msg_control = {
        "control": "turn right"
    }

    msg_state = {
        "battery": 100,
        "battery_state": 0,
        "is_controlling_state": 0,
        "is_mission_state": 0,
        "sensor_state": 0,
        "time": "2020.12.12 12:12:12"
    }

    msg_login_request = {
        "username": "Demo",
        "password": "1"
    }

    msg_login_userInforesponse = {
        "response": "success", # or "fail"
        "userInfo": {
            "username": "Demo",
            "password": "1",
            "name": "Nam",
            "phone": "123456789",
            "email": ""
        }
    }

    msg_deliver = {
        "target": {
            "name": "A",
            "x": 0,
            "y": 0,
            "z": 0
        },
        "target": {
            "name": "B",
            "x": 1,
            "y": 1,
            "z": 1
        },
        "target": {
            "name": "C",
            "x": 2,
            "y": 2,
            "z": 2
        }
    }

    msg_deliver_response = {
        "response": "success" # or "fail"
        # "target": {
        #     "name": "A",
        #     "x": 0,
        #     "y": 0,
        #     "z": 0
        # }
    }


    while True:
        time.sleep(5)

        msg = msg_state
        msg = json.dumps(msg)
        result = client.publish(topic_state, msg)
        status = result[0]
        if status == 0:
            print(f"Send `{msg}` to topic `{topic_state}`")
        else:
            print(f"Failed to send message to topic {topic_state}")

        

def run():
    client = connect_mqtt()
    client.on_message = on_message
    client.loop_start()
    publish(client)


if __name__ == '__main__':
    run()



