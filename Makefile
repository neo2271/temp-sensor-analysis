# Example for Makefile
# CC = gcc
# CFLAGS1 = -Wall -g -c
# CFLAGS2 = -g

# # Link the two object files together.

# main: main.o function_add.o
# 	${CC} ${CFLAGS2} -o main main.o function_add.o

# # Compile each source file to an object.

# main.o: main.c
# 	${CC} ${CFLAGS1} -o main.o main.c

# function_add.o: function_add.c
# 	${CC} ${CFLAGS1} -o function_add.o function_add.c

# clean:
# 	rm -f main

<<<<<<< HEAD
# ############################################### #
#                    MAKEFILE                     #
# ############################################### #
=======
>>>>>>> 7e2c7cdd42782cb04d38cdb6c9e7d44afdc0cbe3

CC = gcc
CFLAGS1 = -Wall -g -c
CFLAGS2 = -g
<<<<<<< HEAD
# build output directory
OUT_DIR = build
# src directory
SRC_DIR = src

all: out_dir ${OUT_DIR}/temp_sensor_analysis ${OUT_DIR}/temp_sensor_analysis.o

out_dir:
	@mkdir -p ${OUT_DIR}

# Link the two object files together.
${OUT_DIR}/temp_sensor_analysis: ${OUT_DIR}/temp_sensor_analysis.o	
	${CC} ${CFLAGS2} -o ${OUT_DIR}/temp_sensor_analysis ${OUT_DIR}/temp_sensor_analysis.o

# Compile each source file to an object.
${OUT_DIR}/temp_sensor_analysis.o: ${SRC_DIR}/temp_sensor_analysis.c
	${CC} ${CFLAGS1} -o ${OUT_DIR}/temp_sensor_analysis.o ${SRC_DIR}/temp_sensor_analysis.c

clean:
	rm -rf ${OUT_DIR}
=======

# Link the two object files together.

build/temp_sensor_analysis: build/temp_sensor_analysis.o
	${CC} ${CFLAGS2} -o build/temp_sensor_analysis build/temp_sensor_analysis.o

# Compile each source file to an object.

build/temp_sensor_analysis.o: src/temp_sensor_analysis.c
	${CC} ${CFLAGS1} -o build/temp_sensor_analysis.o src/temp_sensor_analysis.c

clean:
	rm -f build/temp_sensor_analysis build/temp_sensor_analysis.o
>>>>>>> 7e2c7cdd42782cb04d38cdb6c9e7d44afdc0cbe3
