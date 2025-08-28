# 📚 My ROS2 Learning Workspace

<div align="center">
  <p>
    This repository contains my coursework and personal projects from a Udemy course on ROS2. It serves as a hands-on log of my progress in learning robotics development.
  </p>
</div>

---

## 📖 About This Repository

Welcome to my ROS2 workspace! I created this repository to compile and practice the concepts I learned while pursuing a robotics course on Udemy. The packages here represent my hands-on work with everything from basic ROS2 architecture to more advanced topics like navigation and computer vision.

This is primarily a learning environment, so you'll find various nodes, launch files, and simulations that I built to solidify my understanding.

---

## ✨ Key Concepts I've Learned & Applied

This coursework has given me hands-on experience with the following core robotics concepts:

* **ROS2 Middleware Architecture**: Gained a solid understanding of how ROS2 works, including creating Nodes, Topics, Publishers/Subscribers, and Services using the `rclpy` (Python) client library.

* **Robot Simulation & Control**: Programmed motion planning and navigation for a simulated **TurtleBot3** in Gazebo, learning to use `ros2_control`, RViz2, and custom `ros2 launch` files for effective testing and debugging.

* **Computer Vision Integration**: Integrated **OpenCV with ROS2** to build real-time image processing pipelines, tackling tasks like object detection and tracking from a live camera feed.

* **Practical Robotics Applications**: Developed skills in publishing sensor data from a simulated robot, controlling its movement through code, and creating modular applications with custom launch files.

---

## 🛠️ Technologies & Tools Used

* **Framework**: ROS2 (Foxy/Galactic)
* **Language**: Python (`rclpy`)
* **Simulation**: Gazebo, RViz2
* **Libraries**: OpenCV

---

## 🚀 How to Run This Workspace

This repository is a collection of different ROS2 packages. To run any of the projects, you'll first need to set up the workspace.

### Setup Instructions

1.  **Clone the Repository** into a new ROS2 workspace's `src` folder.
    ```sh
    mkdir -p ~/my_udemy_ros2_ws/src
    cd ~/my_udemy_ros2_ws/src
    git clone [https://github.com/sriv144/ros_ws.git](https://github.com/sriv144/ros_ws.git) .
    ```

2.  **Build the Workspace**
    ```sh
    cd ~/my_udemy_ros2_ws
    colcon build
    ```

3.  **Source the Workspace**
    * Remember to source the new workspace in any terminal you use.
    ```sh
    source install/setup.bash
    ```

### Launching a Project

Each project or concept might have its own launch file. To run a specific part of the coursework, use `ros2 launch`:

```sh
# Example: Launch a specific simulation or test node
# (You'll need to replace the package and file names with the correct ones)
ros2 launch <package_name> <launch_file_name>.py
