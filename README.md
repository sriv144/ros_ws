# 🤖 Advanced ROS2 Workspace for TurtleBot3

<div align="center">
  <p>
    An advanced Robot Operating System (ROS2) workspace demonstrating motion planning, navigation, and computer vision with a simulated TurtleBot3 in Gazebo.
  </p>
</div>



---

## 📖 Project Overview

This repository showcases a deep integration of **ROS2** concepts to perform complex robotics tasks. It provides a complete environment for simulating a TurtleBot3 robot, implementing autonomous navigation, and performing real-time image processing with OpenCV. The project is built using `rclpy` and leverages the full ROS2 ecosystem for debugging, control, and modular application development.

---

## ✨ Core Features & Skills Demonstrated

* **ROS2 Middleware Architecture**: In-depth application of Nodes, Topics, Publishers/Subscribers, and Services using the `rclpy` client library.
* **Motion Planning & Navigation**: Programmed full navigation stacks for a simulated TurtleBot3, utilizing `ros2_control` for hardware abstraction, Gazebo for simulation, and RViz2 for visualization and live debugging.
* **Computer Vision Integration**: Seamlessly integrated ROS2 with OpenCV for real-time image acquisition and processing tasks, including object detection and tracking algorithms.
* **Sensor Data & Control**: Hands-on implementation of nodes for publishing sensor data, controlling robot movement, and creating custom, modular launch files for complex applications.

---

## 🛠️ Technology Stack

| Area              | Technology                                                                                                                                                                                                                                                                                                                          |
| :---------------- | :---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Framework** | ![ROS2](https://img.shields.io/badge/ROS2-Foxy/Galactic-22314E?style=flat&logo=ros&logoColor=white) `ROS2`                                                                                                                                                                                                                           |
| **Language/API** | ![Python](https://img.shields.io/badge/Python-3776AB?style=flat&logo=python&logoColor=white) `Python` ![rclpy](https://img.shields.io/badge/RCLPY-00599C?style=flat&logo=python&logoColor=white) `rclpy`                                                                                                                               |
| **Simulation** | ![Gazebo](https://img.shields.io/badge/Gazebo-000000?style=flat&logo=linux&logoColor=white) `Gazebo` ![RViz2](https://img.shields.io/badge/RViz2-D33682?style=flat&logo=ros&logoColor=white) `RViz2`                                                                                                                                  |
| **Computer Vision**| ![OpenCV](https://img.shields.io/badge/OpenCV-5C3EE8?style=flat&logo=opencv&logoColor=white) `OpenCV`                                                                                                                                                                                                                                |

---

## 🚀 Getting Started

To get this workspace set up on your local machine, follow these steps.

### Prerequisites

* Ubuntu 20.04 (or 22.04)
* ROS2 Foxy Fitzroy or Galactic Geochelone.
* Colcon (ROS2 Build System): `sudo apt install python3-colcon-common-extensions`
* TurtleBot3 Simulation Packages: `sudo apt install ros-<ros2-distro>-turtlebot3*`

### Installation & Build

1.  **Create and Clone**
    * Create a new ROS2 workspace and clone this repository into the `src` folder.
        ```sh
        mkdir -p ~/ros2_ws/src
        cd ~/ros2_ws/src
        git clone [https://github.com/sriv144/ros_ws.git](https://github.com/sriv144/ros_ws.git) .
        ```

2.  **Install Dependencies**
    * Navigate to the root of your workspace and use `rosdep` to install dependencies.
        ```sh
        cd ~/ros2_ws
        rosdep install --from-paths src --ignore-src -r -y
        ```

3.  **Build the Workspace**
    * Build the packages using `colcon`.
        ```sh
        colcon build
        ```

4.  **Source the Workspace**
    * Source the setup file to add the workspace to your environment.
        ```sh
        source install/setup.bash
        ```

---

## 🎮 How to Use

Use `ros2 launch` to run the different applications within this workspace.

1.  **Launch TurtleBot3 Navigation**
    * This command launches the Gazebo simulation with the TurtleBot3 and starts the navigation and motion planning nodes.
        ```sh
        # Replace with your actual launch file
        ros2 launch your_package_name navigation_launch.py
        ```

2.  **Run OpenCV Object Detection**
    * This command starts the camera feed and runs the object detection node.
        ```sh
        # Replace with your actual launch file
        ros2 launch your_vision_package object_detection_launch.py
        ```
