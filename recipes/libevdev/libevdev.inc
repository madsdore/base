DESCRIPTION = "Libevdev is a library for handling evdev kernel devices. It abstracts the evdev ioctls through type-safe interfaces and provides functions to change the appearance of the device."
LICENSE = "X11"
HOMEPAGE = "http://http://www.freedesktop.org/wiki/Software/libevdev/"

RECIPE_TYPES = "machine native"

SRC_URI = "http://www.freedesktop.org/software/libevdev/libevdev-${PV}.tar.xz"

inherit autotools c++

#PROVIDES_${PN} += "libevdev"

DEPENDS += "libc"
DEPENDS_${PN} = "libc"
RDEPENDS_${PN} = "libc"