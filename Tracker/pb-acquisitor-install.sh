echo "Installing pb-acquisitor and its components...\n"

CURRDIR=`pwd`

../Common/pb-common-install.sh

# Cuda
wget https://developer.download.nvidia.com/compute/cuda/repos/ubuntu1804/x86_64/cuda-ubuntu1804.pin
mv cuda-ubuntu1804.pin /etc/apt/preferences.d/cuda-repository-pin-600
apt-key adv --fetch-keys https://developer.download.nvidia.com/compute/cuda/repos/ubuntu1804/x86_64/7fa2af80.pub
add-apt-repository "deb http://developer.download.nvidia.com/compute/cuda/repos/ubuntu1804/x86_64/ /"
apt-get update
apt-get -y install cuda
export PATH=/usr/local/cuda-10.1/bin:/usr/local/cuda-10.1/NsightCompute-2019.1${PATH:+:${PATH}}

# pb libraries
apt install libopenni2-dev -y

# Nite2
wget https://sourceforge.net/projects/roboticslab/files/External/nite/NiTE-Linux-x64-2.2.tar.bz2
tar xvf NiTE-Linux-x64-2.2.tar.bz2
cp -r ./NiTE-Linux-x64-2.2/Include /usr/local/include/nite2
cp ./NiTE-Linux-x64-2.2/Redist/libNiTE2.so /usr/local/lib/

# KinectsV2 Driver
git clone https://github.com/OpenKinect/libfreenect2.git
apt install libusb-1.0-0-dev libturbojpeg0-dev libglfw3-dev -y
cd libfreenect2
mkdir build && cd build
cmake .. -DCMAKE_INSTALL_PREFIX=$HOME/freenect2
make
make install
cp ../platform/linux/udev/90-kinect2.rules /etc/udev/rules.d/
cp ~/freenect2/lib/OpenNI2/Drivers/* /usr/lib/OpenNI2/Drivers/
mkdir CURRDIR/libs
cp -R ../Redist CURRDIR/libs/NiTE2

cd CURRDIR

# Build the acquisitor
echo "Building pb-acquisitor"
make -j4
