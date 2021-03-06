cmake_minimum_required(VERSION 2.8.3)
project(sb_vision)

find_package(
  catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  genmsg
  sb_msgs
  cv_bridge
  image_transport
)

find_package(OpenCV REQUIRED)

add_message_files(
  FILES
  Num.msg
)

generate_messages(
)

catkin_package(
   CATKIN_DEPENDS
   message_runtime roscpp rospy std_msgs 
)

include_directories(
 ${catkin_INCLUDE_DIRS}
 ${OpenCV_INCLUDE_DIRS}
 ${PROJECT_BINARY_DIR}
)
add_subdirectory(src)

#---------Simon's Vision Code------------
add_executable(image_stitching_simon src/image_stitching_simon.cpp)
target_link_libraries( image_stitching_simon ${catkin_LIBRARIES} ${OpenCV_LIBS})

add_executable(camera_publisher src/camera_publisher.cpp src/Camera.h src/Camera.cpp)
target_link_libraries( camera_publisher ${catkin_LIBRARIES} ${OpenCV_LIBS})

add_executable(camera_subscriber src/camera_subscriber.cpp)
target_link_libraries(camera_subscriber ${catkin_LIBRARIES} ${OpenCV_LIBS})

add_executable(pylon_filter src/PylonFilter.cpp)
target_link_libraries(pylon_filter ${catkin_LIBRARIES} ${OpenCV_LIBS})
#----------------------------------------


add_executable(CameraCal src/Perspective_Transform/Camera_Cal/sample_camera_calibration.cpp)
target_link_libraries( CameraCal ${catkin_LIBRARIES} ${OpenCV_LIBS})

add_executable(ObjectDetect src/ObjectDetect.cpp)
target_link_libraries( ObjectDetect ${catkin_LIBRARIES} ${OpenCV_LIBS})

#add_executable( ipm src/Perspective_Transform/ipm_code/main.cpp 
#			src/Perspective_Transform/ipm_code/IPM.cpp 
#			src/Perspective_Transform/ipm_code/IPM.h)
#target_link_libraries( ipm ${catkin_LIBRARIES} ${OpenCV_LIBS})

add_executable( Pylon_Detector src/Pylon_Detector/Pylon_Detector.cpp )
target_link_libraries( Pylon_Detector ${catkin_LIBRARIES} ${OpenCV_LIBS})


add_executable( vision src/vision.cpp )
target_link_libraries( vision ${catkin_LIBRARIES} ${OpenCV_LIBS} filter ipm)

#add_executable( filter src/filter.cpp )
#target_link_libraries( filter ${catkin_LIBRARIES} ${OpenCV_LIBS})

#add_executable( ipm src/IPM.cpp )
#target_link_libraries( ipm ${catkin_LIBRARIES} ${OpenCV_LIBS})






