/*
 * Copyright (C) 2019 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <android-base/properties.h>
#include "property_service.h"
#include "vendor_init.h"

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

using android::init::property_set;

void property_override(char const prop[], char const value[])
{
    prop_info *pi;
    pi = (prop_info*) __system_property_find(prop);

    if (pi) {
        __system_property_update(pi, value, strlen(value));
    } else {
        __system_property_add(prop, strlen(prop), value, strlen(value));
	}
}

/* Redmi K20 Pro China */
void load_raphael() {
    property_override("ro.product.model", "Redmi K20 Pro");
    property_override("ro.build.product", "raphael");
    property_override("ro.product.device", "raphael");
    property_override("ro.build.description", "raphael-user 10 QKQ1.190825.002 V11.0.5.0.QFKCNXM release-keys");
    property_override("ro.build.fingerprint", "Xiaomi/raphael/raphael:10/QKQ1.190825.002/V11.0.5.0.QFKCNXM:user/release-keys");
}

/* Redmi K20 Pro Premium Edition */
void load_raphaels() {
    property_override("ro.product.model", "Redmi K20 Pro Premium Edition");
    property_override("ro.build.product", "raphael");
    property_override("ro.product.device", "raphael");
    property_override("ro.build.description", "raphael-user 10 QKQ1.190825.002 V11.0.5.0.QFKCNXM release-keys");
    property_override("ro.build.fingerprint", "Xiaomi/raphael/raphael:10/QKQ1.190825.002/V11.0.5.0.QFKCNXM:user/release-keys");
}

/* Mi 9T Pro EEA */
/* Mi 9T Pro Global */
/* Mi 9T Pro Russia */
void load_raphaelglobal() {
    property_override("ro.product.model", "Mi 9T Pro");
    property_override("ro.build.product", "raphael");
    property_override("ro.product.device", "raphael");
    property_override("ro.build.description", "raphael-user 10 QKQ1.190825.002 V11.0.3.0.QFKEUXM release-keys");
    property_override("ro.build.fingerprint", "Xiaomi/raphael_eea/raphael:10/QKQ1.190825.002/V11.0.3.0.QFKEUXM:user/release-keys");
}

/* Redmi K20 Pro India */
void load_raphaelin() {
    property_override("ro.product.model", "Redmi K20 Pro");
    property_override("ro.build.product", "raphaelin");
    property_override("ro.product.device", "raphaelin");
    property_override("ro.build.description", "raphaelin-user 10 QKQ1.190825.002 V11.0.3.0.QFKINXM release-keys");
    property_override("ro.build.fingerprint", "Xiaomi/raphaelin/raphaelin:10/QKQ1.190825.002/V11.0.3.0.QFKINXM:user/release-keys");
}

void vendor_load_properties() {
    std::string reg = android::base::GetProperty("ro.boot.hwc", "");
    std::string ver = android::base::GetProperty("ro.boot.hwversion", "");

    if (reg.find("CN") != std::string::npos) {
        if (ver.find("4.9.0") != std::string::npos) {
            load_raphael();
        } else {
            load_raphaels();
        }
    } else if (reg.find("GLOBAL") != std::string::npos) {
        load_raphaelglobal();
    } else if (reg.find("INDIA") != std::string::npos) {
        load_raphaelin();
    }
}
