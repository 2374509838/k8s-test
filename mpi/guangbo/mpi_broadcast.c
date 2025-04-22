#include <mpi.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    int rank, size;
    int data = 0;

    // 初始化MPI环境
    MPI_Init(&argc, &argv);

    // 获取进程编号和总进程数
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // 进程0广播数据
    if (rank == 0) {
        data = 42;  // 进程0设置数据
        printf("Process %d broadcasting data: %d\n", rank, data);
    }

    // 广播数据到所有进程
    MPI_Bcast(&data, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // 所有进程接收并打印数据
    printf("Process %d received data: %d\n", rank, data);

    // 结束MPI环境
    MPI_Finalize();
    return 0;
}

