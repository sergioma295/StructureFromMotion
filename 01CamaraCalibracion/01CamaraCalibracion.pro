TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

# Agregamos librerías de VisionWorks
INCLUDEPATH += -I/home/dawid/code/build-visionworks/install/include
LIBS += -L/home/dawid/code/build-visionworks/install/lib -lvisionworks

# Agregamos librerías de OpenCV
INCLUDEPATH += -I/usr/local/include/opencv
INCLUDEPATH += -I/usr/local/include/opencv2
INCLUDEPATH += -I/usr/local/include
LIBS += -L/usr/local/lib -lopencv_cudabgsegm -lopencv_cudaobjdetect -lopencv_cudastereo -lopencv_stitching -lopencv_cudafeatures2d -lopencv_superres -lopencv_cudacodec -lopencv_videostab -lopencv_cudaoptflow -lopencv_cudalegacy -lopencv_photo -lopencv_cudawarping -lopencv_cudaimgproc -lopencv_cudafilters -lopencv_aruco -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_cvv -lopencv_dpm -lopencv_face -lopencv_freetype -lopencv_fuzzy -lopencv_hdf -lopencv_img_hash -lopencv_line_descriptor -lopencv_optflow -lopencv_reg -lopencv_rgbd -lopencv_saliency -lopencv_sfm -lopencv_stereo -lopencv_structured_light -lopencv_viz -lopencv_phase_unwrapping -lopencv_surface_matching -lopencv_tracking -lopencv_datasets -lopencv_text -lopencv_dnn -lopencv_plot -lopencv_xfeatures2d -lopencv_shape -lopencv_video -lopencv_ml -lopencv_cudaarithm -lopencv_ximgproc -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_flann -lopencv_xobjdetect -lopencv_imgcodecs -lopencv_objdetect -lopencv_xphoto -lopencv_imgproc -lopencv_core -lopencv_cudev

# Agregamos librería filessytem.
LIBS += -lstdc++fs

SOURCES += \
        calibradorcamara.cpp \
        main.cpp

HEADERS += \
    calibradorcamara.h
