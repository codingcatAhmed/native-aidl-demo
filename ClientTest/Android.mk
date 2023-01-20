LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

# Set the module name.
LOCAL_MODULE := fibonacci-client
LOCAL_EXECUTABLE := true

# Set the module dependencies.
LOCAL_SHARED_LIBRARIES := \
    libbinder \
    libutils \
    libandroid

# Set the module source files.
LOCAL_SRC_FILES := fibonacci-client.cpp IFibonacciService.cpp

# Set the module include directories.
LOCAL_C_INCLUDES := $(LOCAL_PATH)/include

# Set the module flags.
LOCAL_LDFLAGS += -llog

include $(BUILD_EXECUTABLE)
