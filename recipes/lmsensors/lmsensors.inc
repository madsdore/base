DESCRIPTION = "LM sensors: Monitoring tool"
HOMEPAGE = "http://www.lm-sensors.org/"

COMPATIBLE_MACHINES = ".*"

inherit make c

DEPENDS = "kernel-dev native:flex native:bison libm"

DEPENDS_${PN} += "libc libm"
RDEPENDS_${PN} += "libc libm"

SRC_URI = "http://dl.lm-sensors.org/lm-sensors/releases/lm_sensors-${PV}.tar.bz2"
S = "${SRCDIR}/lm_sensors-${PV}"

do_compile[prefuncs] += "do_compile_remove_prefix"
do_compile_remove_prefix () {
	sed -i -e 's/\(PREFIX :=\).*/\1\${prefix}/' Makefile
	sed -i -e 's/\(CC :=\).*/\1\"${CC}"/' Makefile
}

do_compile() {
	export PREFIX=${prefix}
        oe_runmake \
		LINUX=${HOST_SYSROOT}${kernelsrcdir} \
		TARGET_ARCH=${TARGET_ARCH} \
		user PROG_EXTRA=sensors
}

do_install() {
        oe_runmake user_install DESTDIR=${D}

        install -d ${D}${mandir}
        rm -rf ${D}${mandir}/*
        mv ${D}/usr/man/ ${D}${mandir}
}

PACKAGES = "${PN}-dbg ${PN}-doc ${PN}-dev ${PN}-locale ${PN}-libsensors ${PN}"
inherit auto-package-utils
AUTO_PACKAGE_UTILS = "fancontrol isadump isaset pwmconfig sensors-detect sensors sensors-conf-convert"
RDEPENDS_${PN} += "${AUTO_PACKAGE_UTILS_PACKAGES}"

PROVIDES_${PN}-libsensors += "libsensors"
PROVIDES_${PN}-libsensors[qa] += "is-library"
DEPENDS_${PN}-libsensors += "libc libm"
RDEPENDS_${PN}-libsensors += "libc libm"

DEPENDS_${PN}-sensors += "libc libsensors"
RDEPENDS_${PN}-sensors += "libc libsensors"

DEPENDS_${PN}-dev += "libsensors"

FILES_${PN}-dev += "${libdir}/libsensors.so"
FILES_${PN}-libsensors += "${libdir}/libsensors.so.*"
