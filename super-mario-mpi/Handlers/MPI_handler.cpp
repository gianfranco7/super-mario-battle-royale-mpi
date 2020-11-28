#include "mpi.h"
using namespace std;

class MPI_handler
{
    int my_id, num_processes;
    MPI_Status status;

public:
    MPI_handler();
    ~MPI_handler();
};

MPI_handler::MPI_handler()
{
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &num_processes);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_id);
}

MPI_handler::Broadcast()
{
    MPI_Broadcast();
}

MPI_handler::~MPI_handler()
{
    
}
