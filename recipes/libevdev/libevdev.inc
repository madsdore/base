DESCRIPTION = "Libevdev is a library for handling evdev kernel devices. It abstracts the evdev ioctls through type-safe interfaces and provides functions to change the appearance of the device."
LICENSE = "X11 License"
HOMEPAGE = "http://http://www.freedesktop.org/wiki/Software/libevdev/"

RECIPE_TYPES = "machine native"

SRC_URI = "http://www.freedesktop.org/software/libevdev/libevdev-${PV}.tar.xz"

inherit autotools c++

# PACKAGES =+ "${PN}-staticdev ${PN}-utils ${PN}-utils-dbg"
# FILES_${PN} += "${libdir}/libtiffxx.so.*"
# FILES_${PN}-dev += "${libdir}/libtiffxx.so ${libdir}/libtiffxx.la"
# FILES_${PN}-staticdev = "${libdir}/libtiffxx.a"
# FILES_${PN}-dbg += "${libdir}/.debug/libtiffxx.so*"
# FILES_${PN}-utils = "${bindir}/*"
# FILES_${PN}-utils-dbg += "${bindir}/.debug/"
