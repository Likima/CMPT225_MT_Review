//
// Created by tangb on 2024-10-14.
//

#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

class circular_queue {
public:
    explicit circular_queue(int s);

    ~circular_queue();
    circular_queue(const circular_queue& other);

    void enqueue(int value);
    int dequeue();

    [[nodiscard]] bool is_empty() const;
    [[nodiscard]] bool is_full() const;


private:
    int front_idx;
    int rear_idx;
    int size;
    int capacity;
    int* c;
};



#endif //CIRCULAR_QUEUE_H
