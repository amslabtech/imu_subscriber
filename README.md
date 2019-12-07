# imu_subscriber

IMUからのデータを受けるsubscriberのサンプルプログラム．基本的にどのPCからも利用できる（はず）．


## dependancy
- MqttClass
- imu_structure.hpp



## build
```
git clone https://github.com/amslabtech/imu_subscriber.git
cd imu_subscriber
...ここでCMakeList.txtの編集 MqttClassのincludeディレクトリをセット
mkdir build
cd build
cmake ..
make
```


