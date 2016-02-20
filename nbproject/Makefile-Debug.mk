#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-MacOSX
CND_DLIB_EXT=dylib
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/AppDelegate.o \
	${OBJECTDIR}/BrandCard.o \
	${OBJECTDIR}/BrandGridView.o \
	${OBJECTDIR}/CategoryCard.o \
	${OBJECTDIR}/CategoryView.o \
	${OBJECTDIR}/GridView.o \
	${OBJECTDIR}/ShopCard.o \
	${OBJECTDIR}/ShopCollectionView.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../UIKit/dist/Debug/GNU-MacOSX -lUIKit `pkg-config --libs clutter-1.0` `pkg-config --libs glib-2.0` `pkg-config --libs clutter-gst-3.0` `pkg-config --libs gdk-pixbuf-2.0` `pkg-config --libs cairo` -lm   

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mallinga

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mallinga: ../UIKit/dist/Debug/GNU-MacOSX/libUIKit.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mallinga: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mallinga ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/AppDelegate.o: AppDelegate.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../UIKit `pkg-config --cflags clutter-1.0` `pkg-config --cflags glib-2.0` `pkg-config --cflags clutter-gst-3.0` `pkg-config --cflags gdk-pixbuf-2.0` `pkg-config --cflags cairo` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AppDelegate.o AppDelegate.cpp

${OBJECTDIR}/BrandCard.o: BrandCard.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../UIKit `pkg-config --cflags clutter-1.0` `pkg-config --cflags glib-2.0` `pkg-config --cflags clutter-gst-3.0` `pkg-config --cflags gdk-pixbuf-2.0` `pkg-config --cflags cairo` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BrandCard.o BrandCard.cpp

${OBJECTDIR}/BrandGridView.o: BrandGridView.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../UIKit `pkg-config --cflags clutter-1.0` `pkg-config --cflags glib-2.0` `pkg-config --cflags clutter-gst-3.0` `pkg-config --cflags gdk-pixbuf-2.0` `pkg-config --cflags cairo` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BrandGridView.o BrandGridView.cpp

${OBJECTDIR}/CategoryCard.o: CategoryCard.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../UIKit `pkg-config --cflags clutter-1.0` `pkg-config --cflags glib-2.0` `pkg-config --cflags clutter-gst-3.0` `pkg-config --cflags gdk-pixbuf-2.0` `pkg-config --cflags cairo` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CategoryCard.o CategoryCard.cpp

${OBJECTDIR}/CategoryView.o: CategoryView.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../UIKit `pkg-config --cflags clutter-1.0` `pkg-config --cflags glib-2.0` `pkg-config --cflags clutter-gst-3.0` `pkg-config --cflags gdk-pixbuf-2.0` `pkg-config --cflags cairo` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CategoryView.o CategoryView.cpp

${OBJECTDIR}/GridView.o: GridView.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../UIKit `pkg-config --cflags clutter-1.0` `pkg-config --cflags glib-2.0` `pkg-config --cflags clutter-gst-3.0` `pkg-config --cflags gdk-pixbuf-2.0` `pkg-config --cflags cairo` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GridView.o GridView.cpp

${OBJECTDIR}/ShopCard.o: ShopCard.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../UIKit `pkg-config --cflags clutter-1.0` `pkg-config --cflags glib-2.0` `pkg-config --cflags clutter-gst-3.0` `pkg-config --cflags gdk-pixbuf-2.0` `pkg-config --cflags cairo` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ShopCard.o ShopCard.cpp

${OBJECTDIR}/ShopCollectionView.o: ShopCollectionView.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../UIKit `pkg-config --cflags clutter-1.0` `pkg-config --cflags glib-2.0` `pkg-config --cflags clutter-gst-3.0` `pkg-config --cflags gdk-pixbuf-2.0` `pkg-config --cflags cairo` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ShopCollectionView.o ShopCollectionView.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../UIKit `pkg-config --cflags clutter-1.0` `pkg-config --cflags glib-2.0` `pkg-config --cflags clutter-gst-3.0` `pkg-config --cflags gdk-pixbuf-2.0` `pkg-config --cflags cairo` -std=c++11  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:
	cd ../UIKit && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mallinga

# Subprojects
.clean-subprojects:
	cd ../UIKit && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
