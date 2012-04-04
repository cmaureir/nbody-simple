all: include nbody
include:
	make -C include/
nbody: nbody.cpp include/file_utils.o include/bodies_dynamic.o
