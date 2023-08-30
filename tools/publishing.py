# python 3.6

import random
import time
import json
from paho.mqtt import client as mqtt_client


broker = 'localhost'
port = 1883
topic = "sensor/001"
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
    client.username_pw_set("nam", "1")
    client.on_connect = on_connect
    client.connect(broker, port)
    return client

def publish(client):
    id = 0
    tem = 0
    humidity = 0
    pest_counting = 0
    time_repeat = "day"
    time_start = "07:00:00"
    state = "off"
    month = "12"
    day = "12"
    hour = "12"
    minute = "12"
    msg_count = {
    "name_gate" : "farm1",
    "id_device" : {
        "type" : "LoRa",
        "group" : "A",
        "index_node" : 1
    },
    "data" : {
        "id": id,
        "time" : {
            "mm" : month,
            "dd" : day,
            "h" : hour,
            "m" : minute
        },
        "tem": tem,
        "humidity": humidity,
        "pest_counting" : pest_counting
    },
    "state_pump" :
        {
        "state" : state,
        "time_execution" : {
            "time_repeat" : time_repeat,
            "time_start" : time_start
        }
    }
    }
    while True:
        time.sleep(5)
        # msg = f"messages: {msg_count}"
        msg = msg_count
        # print(type(msg))
        msg = json.dumps(msg)
        result = client.publish(topic, msg)
        # result: [0, 1]
        status = result[0]
        if status == 0:
            print(f"Send `{msg}` to topic `{topic}`")
        else:
            print(f"Failed to send message to topic {topic}")
        id += 1
        tem = random.randint(5, 15)
        humidity = random.randint(5, 15)
        pest_counting = random.randint(1,5)
        month = "12"
        day = "12"
        hour = "12"
        minute = "12"
        msg_count = {
            "name_gate": "farm1",
            "id_device": {
                "type": "LoRa",
                "group": "A",
                "index_node": 1
            },
            "data": {
                "id": id,
                "time": {
                    "mm": month,
                    "dd": day,
                    "h": hour,
                    "m": minute
                },
                "tem": tem,
                "humidity": humidity,
                "pest_counting": pest_counting
            },
            "state_pump":
                {
                    "state": state,
                    "time_execution": {
                        "time_repeat": time_repeat,
                        "time_start": time_start
                    }
                }
        }
        

def run():
    client = connect_mqtt()
    client.loop_start()
    publish(client)


if __name__ == '__main__':
    run()


