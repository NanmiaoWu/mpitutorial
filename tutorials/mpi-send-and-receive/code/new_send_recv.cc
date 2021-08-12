//  2021 Nanmiao Wu

//  SPDX-License-Identifier: BSL-1.0
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <mpi.h>
#include <iostream>

int main(int argc, char ** argv){
    MPI_Init(&argc, &argv);
    int rank, n_ranks;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &n_ranks);

    if (n_ranks < 2){
        std::cout << "number of ranks must be greater than 1 \n"; 
    }

    int number;
    if (rank == 0){
        number = -42;
        MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    } else if (rank == 1){
        MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        std::cout << "process 1 recevied number " << number << " from process 0 \n";
    }

    MPI_Finalize();
}
