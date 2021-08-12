//  2021 Nanmiao Wu

//  SPDX-License-Identifier: BSL-1.0
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include<mpi.h>
#include<iostream>

int main(int argc, char ** argv){
    const int PING_PONTG_LIMIT = 10;

    MPI_Init(&argc, &argv);

    int rank, n_ranks;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &n_ranks);

    if (n_ranks != 2){
        std::cout << "Must have 2 process for " << argv[0] << std::endl;
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    int ping_pong_count = 0;
    int partner_rank = (rank + 1) % 2;

    while (ping_pong_count < PING_PONTG_LIMIT){
        if (rank == ping_pong_count % 2){
            ping_pong_count ++;
            MPI_Send(&ping_pong_count, 1, MPI_INT, partner_rank, 0, MPI_COMM_WORLD);
            std::cout << "process " << rank << " increase ping pong count, and send it to process " 
                      << partner_rank << ", and ping pong count is " << ping_pong_count << "\n";
        } else{
            MPI_Recv(&ping_pong_count, 1, MPI_INT, partner_rank, 0, MPI_COMM_WORLD,
                MPI_STATUS_IGNORE);
            std::cout << "process " << rank << " receive ping pong count from process " 
                      << partner_rank << ", and ping pong count is " << ping_pong_count << "\n";
        }
    }

    MPI_Finalize();

}