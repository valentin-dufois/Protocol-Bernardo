echo "Installing openpose and its dependencies"

echo "Installing OpenCV, GLog, gFlags..."
sudo apt install libopencv-dev libgoogle-glog-dev libgflags-dev libhdf5-dev libatlas-base-dev libssl-dev -y

echo "Downloading OpenPose"
rm cudnn-8.0-linux-x64-v5.1.tgz && sudo ldconfig
cd openpose
mkdir build && cd build

echo "Installing CuDNN..."
CUDNN_URL="http://developer.download.nvidia.com/compute/redist/cudnn/v5.1/cudnn-8.0-linux-x64-v5.1.tgz"
wget -c ${CUDNN_URL}
sudo tar -xzf cudnn-8.0-linux-x64-v5.1.tgz -C /usr/local
rm cudnn-8.0-linux-x64-v5.1.tgz && sudo ldconfig

echo "Installing latest cmake version"i
sudo apt-get remove cmake cmake-data
wget https://github.com/Kitware/CMake/releases/download/v3.16.0-rc3/cmake-3.16.0-rc3.tar.gz
tar -xzf cmake-3.16.0-rc3.tar.gz && cd cmake-3.16.0-rc3
./bootstrap
make -j`nproc`
sudo make install
cd ../
rm -rf cmake-3.16.0-rc3
rm -rf cmake-3.16.0-rc3.tar.gz

echo "Running cmake on openpose"
cmake ..
make -j`nproc`
sudo make install

