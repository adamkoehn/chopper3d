#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([FULL-PACKAGE-NAME], [VERSION], [BUG-REPORT-ADDRESS])
AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX

# Checks for libraries.
PKG_CHECK_MODULES([SDL], [sdl2], [], [AC_MSG_ERROR([sdl2 could not be found])])
PKG_CHECK_MODULES([GLEW], [glew], [], [AC_MSG_ERROR([glew could not be found])])
PKG_CHECK_MODULES([GLM], [glm], [], [AC_MSG_ERROR([glm could not be found])])
PKG_CHECK_MODULES([ASSIMP], [assimp], [], [AC_MSG_ERROR([assimp could not be found])])
PKG_CHECK_MODULES([STB], [stb], [], [AC_MSG_ERROR([stb could not be found])])

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AM_INIT_AUTOMAKE([subdir-objects])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
