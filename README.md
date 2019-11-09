# Protocol Bernardo (PB)

![plateform: macos & linux](https://img.shields.io/badge/plateform-macos%20%7C%20linux-lightgrey)

## How to use

PB is composed of multiple components that talks with each other through the network.
A full PB network is composed of:
* One pb-master executing tracking tasks
* One or more pb-acquisitor on machines connected to tracking devices
* One or more pb-broadcaster on machines using the tracking information from the pb-master

PB-terminal is only used when there is a need to manipulate the current layout used by the master.

All applications can run on the same machine. As long as they are on the same network, they will connect with each other automatically. Network operations rely on **Boost Asio**, information is sent using **Protobuf** for compression and standardization.

Every component except pb-terminal works on macos and linux; pb-terminal works only on macos.

Each component of PB executes a specific task

### pb-common

This is a dynamic library used by pb-acquisitor, pb-master and pb-broadcaster. It contains the networking codes, skeleton structures and more.

#### Dependencies

pb-common relies on multiple libraries:
* **Boost**: for networking, `libboost_system` must be embedded
* **Gflags**: Command-line parameters
* **Protobuf**: For networking compression

### pb-master

The pb-master preforms tracking operations on bodies it receives from connected pb-acquisitors. These operations merge bodies that are coming from different devices but who represent the same person. This allows for continuous tracking across multiple devices.

Tracking operations require a Layout defining the placement of each tracking device in the real world. Layouts are created and updated with the pb-terminal application. A pb-terminal can set the layout then disconnect, the layout will stay active.

#### Dependencies

pb-master relies only on the **pb-common** library.

### pb-terminal

The pb-terminal application purpose is to offer a convenient interface for building layouts used by pb-master, and monitoring activity on the master. An active connection to a pb-master is required for the application for execute.

When opening a layout on the terminal, the master start using it for tracking operations.

Layouts are stored on the master machine.

#### Dependencies

The pb-terminal uses the Swift Packet Manager for its dependencies. Xcode 11 handles this for you. 

### pb-acquisitor

The pb-acquisitor handles the Human Pose Estimation (HPE) part of the application. It searches for compatible
tracking devices connected to the machine on which it is running (for now, only Kinects V2 are supported),
connects to them, and then stream the detected bodies to the master application. 

#### Dependencies

pb-acquisitor relies on multiple libraries:
* **pb-common**
* **OpenNI2** with **libfreenect2** driver: Connection to the Kinects)
* **NiTE2**: HPE for OpenNI2 devices
* **OpenCV**: Live view of the device (Todo)

### pb-acquisitor-launcher

At this stage of development, the pb-acquisitor application isn't very stable as the NiTE library tends to segfault without warning.

To handle this, the acquisitor launcher will restart the pb-acquisitor if it crashes. Since the components autoconnects with each other automatically, downtime is limited.
Work is planned, to stabilize the acquisitor.

#### Dependencies

The acquisitor launcher relies only on **Boost** headers.

### pb-broadcaster

The pb-broadcaster task is to take the output of the master and display a visual representation of it. 

This hasn't been developed yet.
