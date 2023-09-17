#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <ctime>

#define NUM_THREADS 4

int nthreads;

void *say_hello(void *);

int main(int argc, char **argv) {
    int i, *thr_num;
    pthread_t *thr_ids;

    switch (argc) {
        case 1:
            nthreads = NUM_THREADS;
            break;
        case 2:
            nthreads = atoi(argv[1]);
            if (nthreads < 1) {
                std::cerr << "Error: wrong number of threads.\n"
                             "Usage:\n"
                             " " << argv[0] << " [number_of_threads]\n"
                             "number_of_threads should be > 0\n"
                             "Using default number of threads (" << NUM_THREADS << ").\n";
                nthreads = NUM_THREADS;
            }
            break;
        default:
            std::cerr << "Error: wrong number of parameters.\n"
                         "Usage:\n"
                         " " << argv[0] << " [number_of_threads]\n";
            exit(EXIT_FAILURE);
    }

    thr_ids = new pthread_t[nthreads];
    thr_num = new int[nthreads];

    if (!thr_num || !thr_ids) {
        std::cerr << "Error: Can't allocate memory." << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "\nHola Amigos! I'm the main thread" << std::endl;

    for (i = 0; i < nthreads; i++) {
        thr_num[i] = i + 1;
        pthread_create(&thr_ids[i], nullptr, say_hello, &thr_num[i]);
    }

    for (i = 0; i < nthreads; i++) {
        pthread_join(thr_ids[i], nullptr);
    }

    delete[] thr_num;
    delete[] thr_ids;

    return EXIT_SUCCESS;
}

void *say_hello(void *arg) {
    int thr_index, rdm_message;
    thr_index = *((int *) arg);
    srand(time(NULL));
    rdm_message = rand() % 4;

    switch (rdm_message) {
        case 0:
            std::cout << "Hola amigos! I'm thread " << thr_index << " of " << nthreads << ". My ID is " << pthread_self() << std::endl;
            break;
        case 1:
            std::cout << "Aloha honua! I'm thread " << thr_index << " of " << nthreads << ". My ID is " << pthread_self() << std::endl;
            break;
        case 2:
            std::cout << "Hello peers! I'm thread " << thr_index << " of " << nthreads << ". My ID is " << pthread_self() << std::endl;
            break;
        case 3:
            std::cout << "Hallo Leute! I'm thread " << thr_index << " of " << nthreads << ". My ID is " << pthread_self() << std::endl;
            break;
        default:
            std::cout << "Konichiwa! I have no father. I was created by Magic!" << std::endl;
            break;
    }

    pthread_exit(EXIT_SUCCESS);
}
