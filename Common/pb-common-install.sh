echo "Installing installing the pb-common library and its dependencies...\n"

CURRDIR=`pwd`

mkdir ~/pb-install && cd ~/pb-install

# G++, git & support packages
apt install gcc-8 cmake -y

# Boost 1.71
wget https://dl.bintray.com/boostorg/release/1.71.0/source/boost_1_71_0.tar.gz
tar --bzip2 -xf boost_1_71_0.tar.gz
cd boost_1_71_0
./bootstrap.sh
./b2 install
cd ../

# pb libraries
apt installlibgflags-dev libgpr1-dev libprotobuf-dev libboost-dev libglm-dev -y

cd CURRDIR

echo "\n\nBuilding pb-common"
make -j4
make install

# Update libraries
ldconfig
