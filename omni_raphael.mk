#
# Copyright (C) 2019 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Release name
PRODUCT_RELEASE_NAME := whyred

$(call inherit-product, build/target/product/embedded.mk)

# Inherit from our custom product configuration
$(call inherit-product, vendor/omni/config/common.mk)

PRODUCT_PROPERTY_OVERRIDES += \
    sys.usb.controller=a800000.dwc3 \
    sys.usb.rndis.func.name=rndis_bam \
    sys.usb.rmnet.func.name=rmnet_bam

PRODUCT_PROPERTY_OVERRIDES += \
    vendor.gatekeeper.disable_spu=true \
    persist.sys.isUsbOtgEnabled=true

PRODUCT_DEFAULT_PROPERTY_OVERRIDES += \
    ro.secure=0 \
    ro.adb.secure=0 \

# Device identifier. This must come after all inclusions.
PRODUCT_NAME := omni_raphael
PRODUCT_DEVICE := raphael
PRODUCT_BRAND := Xiaomi
PRODUCT_MODEL := Redmi K20 Pro
PRODUCT_MANUFACTURER := Xiaomi

PRODUCT_BUILD_PROP_OVERRIDES += \
    PRODUCT_NAME="raphael" \
    TARGET_DEVICE="raphael"
