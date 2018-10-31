final: UtPod_Driver.o UtPod.o Song.o
        g++ -otest  UtPod_Driver.o UtPod.o Song.o
UtPod_Driver.o: UtPod_Driver.cpp UtPod.h Song.h
        g++ -c UtPod_Driver.cpp
UtPod.o: UtPod.cpp UtPod.h Song.h
        g++ -c UtPod.cpp
Song.o: Song.cpp Song.h
        g++ -c Song.cpp
