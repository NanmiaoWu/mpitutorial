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

    int token;

    if (rank != 0){
        MPI_Recv(&token, 1, MPI_INT, rank-1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        std::cout << "process " << rank << " receive from process " << rank - 1 << "\n";
    } else {
        token = -42;
    }
    MPI_Send(&token, 1, MPI_INT, (rank+1)%n_ranks, 0, MPI_COMM_WORLD);

    if (rank == 0){
        MPI_Recv(&token, 1, MPI_INT, n_ranks - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        std::cout << "process " << rank << " receive from process " << n_ranks - 1 << "\n";
    }

    MPI_Finalize();

}