LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := fibonacci-service
LOCAL_EXECUTABLE := true

# Specify the source files for the FibonacciService module.
LOCAL_SRC_FILES := \
    src/main/cpp/FibonacciService.cpp \
    src/main/cpp/IFibonacciService.cpp
		
LOCAL_C_INCLUDES := \
    $(LOCAL_PATH)/src/main/cpp/include
    
LOCAL_LDLIBS := -lbinder -landroid

LOCAL_SHARED_LIBRARIES := \
    libbinder \
    liblog \
    libutils
    
include $(BUILD_EXECUTABLE)
