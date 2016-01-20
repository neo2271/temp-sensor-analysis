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


CC = gcc
CFLAGS1 = -Wall -g -c
CFLAGS2 = -g

# Link the two object files together.

build/temp_sensor_analysis: build/temp_sensor_analysis.o
	${CC} ${CFLAGS2} -o build/temp_sensor_analysis build/temp_sensor_analysis.o

# Compile each source file to an object.

build/temp_sensor_analysis.o: src/temp_sensor_analysis.c
	${CC} ${CFLAGS1} -o build/temp_sensor_analysis.o src/temp_sensor_analysis.c

clean:
	rm -f build/temp_sensor_analysis build/temp_sensor_analysis.o