EXECS=send_recv ping_pong ring new_send_recv new_ping_pong new_ring
MPICC?=mpicc
MPICXX?=mpic++


CXXFLAGS ?=
CXXFLAGS += -std=c++11

all: ${EXECS}

send_recv: send_recv.c
	${MPICC} -o send_recv send_recv.c

new_send_recv: new_send_recv.cc
	${MPICXX}  $(CXXFLAGS)  -o  new_send_recv new_send_recv.cc  

ping_pong: ping_pong.c
	${MPICC} -o ping_pong ping_pong.c

new_ping_pong: new_ping_pong.cc
	${MPICXX}  $(CXXFLAGS) -o new_ping_pong new_ping_pong.cc

ring: ring.c
	${MPICC} -o ring ring.c

new_ring: new_ring.cc
	${MPICXX}  $(CXXFLAGS) -o new_ring new_ring.cc

clean:
	rm -f ${EXECS}

