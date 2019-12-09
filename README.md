# imu_subscriber

IMUからのデータを受けるsubscriberのサンプルプログラム．基本的にどのPCからも利用できる．


## dependancy
- MqttClass
- RTIMULib2


## build
```
git clone https://github.com/amslabtech/imu_subscriber.git
cd imu_subscriber
mkdir build
cd build
cmake ..
make
sudo make install
```


## 使用方法

> imu_subscriber
> imu_subscriber 192.168.0.172
> imu_subscriber localhost

など．  
引数がない場合はデフォルトのIPアドレス192.168.0.172（CCV2_IMU)となる．
