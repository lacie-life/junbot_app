# junbot_app

[Qt for Android](https://www.youtube.com/watch?v=w2RRgRGHsDA)

# Installation

1. QMQTT
```
git clone git://code.qt.io/qt/qtmqtt.git
git checkout <version of Qt> # version of Qt: v5.15.2
sudo apt-get install qtbase5-private-dev
qmake => make => make install
```
2. Tools usage

- Install mosquitto and mosquitto-client by following this [link](https://www.digitalocean.com/community/tutorials/how-to-install-and-secure-the-mosquitto-mqtt-messaging-broker-on-ubuntu-18-04)
- Using mosquitto for sub topic in publishing.py (option)
- Config user/pass (option)
- Install paho-mqtt for run publishing.py
```
pip install paho-mqtt
```
- Default mqtt broker will be localhost:1883

3. Run


# TODO:

- [x] Clean code and build 
- [x] Add feature table and permission
- [x] Login Screen and Login feature, get data, compress to Json format and send to junbot_gui => check login status and return
- [x] Connect via MQTT Broker and visual Robot Status in Home Screen
- [x] Send control message to Robot by Json format (Update this feature in junbot_gui)
- [x] Get DeliveryTarget from junbot_gui via MQTT Broker and visual in Control Screen
- [x] Send DeliveryTarget to Robot by Json format (Update this feature in junbot_gui)
- [x] Notify robot status
- [ ] Test and fix bug

