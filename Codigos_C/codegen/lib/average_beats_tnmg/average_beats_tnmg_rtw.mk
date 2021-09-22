###########################################################################
## Makefile generated for component 'average_beats_tnmg'. 
## 
## Makefile     : average_beats_tnmg_rtw.mk
## Generated on : Tue Sep 21 22:59:41 2021
## Final product: ./average_beats_tnmg.lib
## Product type : static-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# CMD_FILE                Command file
# MODELLIB                Static library target

PRODUCT_NAME              = average_beats_tnmg
MAKEFILE                  = average_beats_tnmg_rtw.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2021a
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2021a/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = D:/Doutorado/SNR/Implementação_TNMG/Codigos_C/codegen/lib/average_beats_tnmg
TGT_FCN_LIB               = None
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = .
CMD_FILE                  = average_beats_tnmg_rtw.rsp
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 
MODELLIB                  = average_beats_tnmg.lib

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          LCC-win64 v2.4.1 | gmake (64-bit Windows)
# Supported Version(s):    2.4.1
# ToolchainInfo Version:   2021a
# Specification Revision:  1.0
# 

#-----------
# MACROS
#-----------

SHELL              = cmd
LCC_ROOT           = $(MATLAB_ROOT)/sys/lcc64/lcc64
LCC_BUILDLIB       = $(LCC_ROOT)/bin/buildlib
LCC_LIB            = $(LCC_ROOT)/lib64
MW_EXTERNLIB_DIR   = $(MATLAB_ROOT)/extern/lib/win64/microsoft
MW_LIB_DIR         = $(MATLAB_ROOT)/lib/win64
TOOLCHAIN_INCLUDES = -I$(LCC_ROOT)/include64

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: Lcc-win64 C Compiler
CC_PATH = $(LCC_ROOT)/bin
CC = "$(CC_PATH)/lcc64"

# Linker: Lcc-win64 Linker
LD_PATH = $(LCC_ROOT)/bin
LD = "$(LD_PATH)/lcclnk64"

# Archiver: Lcc-win64 Archiver
AR_PATH = $(LCC_ROOT)/bin
AR = "$(AR_PATH)/lcclib64"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%\bin\win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -Fo
LDDEBUG             =
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG = /out:
MEX_DEBUG           = -g
RM                  = @del /F
ECHO                = @echo
MV                  = @move
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              =
CFLAGS               = -c -w -noregistrylookup -nodeclspec -I$(LCC_ROOT)/include64
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = -s -L$(LCC_LIB) $(LDFLAGS_ADDITIONAL)
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -dll -entry LibMain -s -L$(LCC_LIB) $(LDFLAGS_ADDITIONAL) $(DEF_FILE)



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./average_beats_tnmg.lib
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -ID:/Doutorado/SNR/Implementação_TNMG/Codigos_C -I$(MATLAB_ROOT)/extern/include

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_CUSTOM = 
DEFINES_STANDARD = -DMODEL=average_beats_tnmg

DEFINES = $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/average_beats_tnmg_data.c $(START_DIR)/rt_nonfinite.c $(START_DIR)/rtGetNaN.c $(START_DIR)/rtGetInf.c $(START_DIR)/average_beats_tnmg_initialize.c $(START_DIR)/average_beats_tnmg_terminate.c $(START_DIR)/average_beats_tnmg.c $(START_DIR)/diff.c $(START_DIR)/median.c $(START_DIR)/quickselect.c $(START_DIR)/squeeze.c $(START_DIR)/nanmedian.c $(START_DIR)/prctile.c $(START_DIR)/nanmean.c $(START_DIR)/nanvar.c $(START_DIR)/ECG_peak_detect_mod_with_derivative.c $(START_DIR)/minOrMax.c $(START_DIR)/find.c $(START_DIR)/nanstd.c $(START_DIR)/colon.c $(START_DIR)/my_butter_coeffs.c $(START_DIR)/lp2hp.c $(START_DIR)/mldivide.c $(START_DIR)/eig.c $(START_DIR)/eigHermitianStandard.c $(START_DIR)/xnrm2.c $(START_DIR)/xzlartg.c $(START_DIR)/xzhgeqz.c $(START_DIR)/xzlanhs.c $(START_DIR)/peakdetect.c $(START_DIR)/nullAssignment.c $(START_DIR)/xhseqr.c $(START_DIR)/xdlanv2.c $(START_DIR)/myfiltfilt.c $(START_DIR)/average_beats_tnmg_emxutil.c $(START_DIR)/average_beats_tnmg_emxAPI.c $(START_DIR)/average_beats_tnmg_rtwutil.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = average_beats_tnmg_data.obj rt_nonfinite.obj rtGetNaN.obj rtGetInf.obj average_beats_tnmg_initialize.obj average_beats_tnmg_terminate.obj average_beats_tnmg.obj diff.obj median.obj quickselect.obj squeeze.obj nanmedian.obj prctile.obj nanmean.obj nanvar.obj ECG_peak_detect_mod_with_derivative.obj minOrMax.obj find.obj nanstd.obj colon.obj my_butter_coeffs.obj lp2hp.obj mldivide.obj eig.obj eigHermitianStandard.obj xnrm2.obj xzlartg.obj xzhgeqz.obj xzlanhs.obj peakdetect.obj nullAssignment.obj xhseqr.obj xdlanv2.obj myfiltfilt.obj average_beats_tnmg_emxutil.obj average_beats_tnmg_emxAPI.obj average_beats_tnmg_rtwutil.obj

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS) /out:$(PRODUCT) @$(CMD_FILE)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.obj : %.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


%.obj : D:/Doutorado/SNR/Implementação_TNMG/Codigos_C/%.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


average_beats_tnmg_data.obj : $(START_DIR)/average_beats_tnmg_data.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rt_nonfinite.obj : $(START_DIR)/rt_nonfinite.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rtGetNaN.obj : $(START_DIR)/rtGetNaN.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


rtGetInf.obj : $(START_DIR)/rtGetInf.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


average_beats_tnmg_initialize.obj : $(START_DIR)/average_beats_tnmg_initialize.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


average_beats_tnmg_terminate.obj : $(START_DIR)/average_beats_tnmg_terminate.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


average_beats_tnmg.obj : $(START_DIR)/average_beats_tnmg.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


diff.obj : $(START_DIR)/diff.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


median.obj : $(START_DIR)/median.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


quickselect.obj : $(START_DIR)/quickselect.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


squeeze.obj : $(START_DIR)/squeeze.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


nanmedian.obj : $(START_DIR)/nanmedian.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


prctile.obj : $(START_DIR)/prctile.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


nanmean.obj : $(START_DIR)/nanmean.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


nanvar.obj : $(START_DIR)/nanvar.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


ECG_peak_detect_mod_with_derivative.obj : $(START_DIR)/ECG_peak_detect_mod_with_derivative.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


minOrMax.obj : $(START_DIR)/minOrMax.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


find.obj : $(START_DIR)/find.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


nanstd.obj : $(START_DIR)/nanstd.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


colon.obj : $(START_DIR)/colon.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


my_butter_coeffs.obj : $(START_DIR)/my_butter_coeffs.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


lp2hp.obj : $(START_DIR)/lp2hp.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


mldivide.obj : $(START_DIR)/mldivide.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


eig.obj : $(START_DIR)/eig.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


eigHermitianStandard.obj : $(START_DIR)/eigHermitianStandard.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xnrm2.obj : $(START_DIR)/xnrm2.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xzlartg.obj : $(START_DIR)/xzlartg.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xzhgeqz.obj : $(START_DIR)/xzhgeqz.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xzlanhs.obj : $(START_DIR)/xzlanhs.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


peakdetect.obj : $(START_DIR)/peakdetect.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


nullAssignment.obj : $(START_DIR)/nullAssignment.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xhseqr.obj : $(START_DIR)/xhseqr.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


xdlanv2.obj : $(START_DIR)/xdlanv2.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


myfiltfilt.obj : $(START_DIR)/myfiltfilt.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


average_beats_tnmg_emxutil.obj : $(START_DIR)/average_beats_tnmg_emxutil.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


average_beats_tnmg_emxAPI.obj : $(START_DIR)/average_beats_tnmg_emxAPI.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


average_beats_tnmg_rtwutil.obj : $(START_DIR)/average_beats_tnmg_rtwutil.c
	$(CC) $(CFLAGS) -Fo"$@" $(subst /,\,"$<")


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(subst /,\,$(PRODUCT))
	$(RM) $(subst /,\,$(ALL_OBJS))
	$(ECHO) "### Deleted all derived files."


