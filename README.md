# MPI-labs
A repository housing C-based MPI exercises for hands-on learning in parallel computing.
These labs provide practical exercises to explore parallel programming concepts and techniques.

## About MPI

MPI (Message Passing Interface) is a standardized and portable message-passing system designed for parallel computing. It allows processes to communicate with each other in distributed memory systems, enabling the development of parallel programs across various architectures.


## Instructions

### Compilation and Execution

To compile and execute the .c files in this repository, follow these steps:

1. **Clone the Repository**: 
   ```bash
   git clone https://github.com/HamzaLakouti/MPI-labs.git

2. **Navigate to the Repository Directory**:
   ```bash
   cd MPI-labs
   
3. **Compile the .c Files:**:
   ```bash
   mpicc -o <output_file_name> <input_file_name.c>
      
4. **Execute the Compiled Program**:
   ```bash
   mpirun -np <num_processes> <compiled_executable>

## Contributing
Contributions to this repository are welcome! If you have additional MPI exercises, optimizations, or improvements, feel free to submit a pull request.

Happy parallel computing!
