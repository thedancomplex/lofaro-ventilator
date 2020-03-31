THE_DIR=$(pwd)
TMP_DIR=lofaro-tentilator
mkdir tmp.$TMP_DIR
cd tmp.$TMP_DIR
git clone https://github.com/ROBOTIS-GIT/DynamixelSDK
cd DynamixelSDK/python
sudo python setup.py install
cd $THE_DIR
sudo rm -rf tmp.$TMP_DIR
sudo pip install dynamixel
sudo pip install pyserial
sudo pip install pydynamixel
mkdir tmp.$TMP_DIR
cd tmp.$TMP_DIR
git clone https://github.com/richard-clark/pydynamixel
cd pydynamixel
sudo python setup.py install
cd $THE_DIR
sudo rm -rf tmp.$TMP_DIR
