#include<iostream>
#include "include/LinkedList.h"


LinkedList::LinkedList():
    head_ptr(nullptr),
    tail_ptr(nullptr),
    size_val(0)
    {}

LinkedList::LinkedList(int input[], int arg_size){
    head_ptr=nullptr;
    
    for(int i=arg_size-1; i>=0; --i){
        if(i==arg_size-1){
            tail_ptr = new LLNode(input[i], nullptr);
            head_ptr = tail_ptr;
            continue;
        }
        head_ptr = new LLNode(input[i], head_ptr);
    }
    size_val = arg_size;
}

LinkedList::LinkedList(std::vector<int>& vec){
    head_ptr=nullptr;
    
    for(int i=vec.size()-1; i>=0; --i){
        if(i==vec.size()-1){
            tail_ptr = new LLNode(vec[i], nullptr);
            head_ptr = tail_ptr;
            continue;
        }
        head_ptr = new LLNode(vec[i], head_ptr);
    }
    size_val = vec.size();
}

LinkedList::LinkedList(const LinkedList& arg_list){
    size_val = arg_list.size_val;
    if(size_val==0)
        return;
    
    head_ptr = tail_ptr = new LLNode(arg_list.head_ptr->value);
    LLNode* curr = arg_list.head_ptr->next;
    while (curr){
        tail_ptr->next = new LLNode(curr->value);
        tail_ptr = tail_ptr->next;
        
        curr = curr->next;
    }
    
}

LinkedList::~LinkedList(){
    LLNode* curr = head_ptr;
    while (head_ptr){
        head_ptr = curr->next;
        curr->next = nullptr;
        delete curr;
        curr = head_ptr;
    }
}

LLNode* LinkedList::head(){
    return head_ptr;
}

LLNode* LinkedList::tail(){
    return tail_ptr;
}

int LinkedList::size(){
    return size_val;
}

bool LinkedList::find(int val){
    LLNode* curr = head_ptr;

    while (curr){
        if(curr->value == val)
            return true;
        curr = curr->next;
    }
    
    return false;
}

bool LinkedList::insert(int val, int pos){
    if(pos<0){
        std::cerr<<"INSERT ERROR: Invalid insert position"<<std::endl;
        return false;
    }
    if(pos>=size_val){
        tail_ptr->next = new LLNode(val, nullptr);
        tail_ptr = tail_ptr->next;
        ++size_val;
        return true;
    }
    if(pos==0){
        head_ptr = new LLNode(val, head_ptr);
        ++size_val;
        return true;
    }
    LLNode* curr = head_ptr;
    int curr_pos=0;
    
    while (curr){
        if(curr_pos == pos-1){
            curr->next = new LLNode(val, curr->next);
            ++size_val;
            return true;
        }
        curr = curr->next;
        ++curr_pos;
    }
    std::cerr<<"INSERT ERROR: Invalid insert position"<<std::endl;
    return false;
}

bool LinkedList::append(int val){
    if(tail_ptr){
        tail_ptr->next = new LLNode(val, nullptr);
        tail_ptr = tail_ptr->next;
    }else{
        head_ptr = tail_ptr = new LLNode(val, nullptr);
    }
    ++size_val;
    return true;
}

void LinkedList::rotate(int n){
    if(n%size_val==0){
        return;
    }
    if(n<0){
        std::cerr<<"ROATATE ERROR: invalid argument for rotation"<<std::endl;
        return;
    }
    n %= size_val; 
    LLNode* curr = head_ptr;
    LLNode* prev = tail_ptr;
    
    for(int i=0; i<n; ++i){
        prev = curr;
        curr = curr->next;
    }

    prev->next = nullptr;
    tail_ptr->next = head_ptr;
    head_ptr = curr;
    tail_ptr = prev;
    
    return;
}

void LinkedList::reverse(){
    if(size_val<=1)
        return;
    
    LLNode* prev = nullptr;
    LLNode* curr = head_ptr;
    LLNode* nxt = head_ptr->next;
    while (nxt){
        curr->next = prev;
        prev = curr;
        curr = nxt;
        nxt = nxt->next;
    }
    curr->next = prev;

    tail_ptr = head_ptr;
    head_ptr  = curr;
    
    return;
}

// void LinkedList::reverse_in_groups(int n){
//     if(size_val<=1 || n==1)
//         return;
//     if(n >= size_val)
//         return reverse();

//     LLNode* prev = nullptr;
//     LLNode* curr = head_ptr;
//     LLNode* nxt = head_ptr->next;
    
    
//     while (nxt){
//         for(int i=0; i<n; ++i){
//             curr->next = prev;
//             prev = curr;
//             curr = nxt;
//             nxt = nxt->next;
//         }
//     }
//     curr->next = prev;

//     tail_ptr = head_ptr;
//     head_ptr  = curr;
    
//     return;
// }

void LinkedList::merge(LLNode* start, LLNode* mid, LLNode* end){
    LinkedList temp_ll;
    LLNode* curr_l = start;
    LLNode* curr_r = mid;
    while (true){
        if(curr_l == mid && curr_r == end->next){
            break;
        }else if(curr_l == mid){
            temp_ll.append(curr_r->value);
            curr_r = curr_r->next;
        }else if(curr_r == end->next){
            temp_ll.append(curr_l->value);
            curr_l = curr_l->next;
        }else if(curr_l->value <= curr_r->value){
            temp_ll.append(curr_l->value);
            curr_l = curr_l->next;
        }else{
            temp_ll.append(curr_r->value);
            curr_r = curr_r->next;
        }
    }
    LLNode* curr = start;
    LLNode* temp_curr = temp_ll.head();
    
    while (curr && temp_curr){
        curr->value = temp_curr->value;
        curr = curr->next;
        temp_curr = temp_curr->next;
    }
    return;
}

void LinkedList::merge_sort_util(LLNode* start, LLNode* end){
    if(start==end)
        return;
    
    LLNode* mid = start;
    LLNode* mid_prev = start;
    LLNode* temp_end = start;

    while (temp_end!=end && temp_end->next!=end){   
        mid_prev = mid;
        mid = mid->next;
        temp_end = temp_end->next->next;
    }
    if(temp_end->next==end){
        mid_prev = mid;
        mid = mid->next;
    }
    merge_sort_util(start, mid_prev);
    merge_sort_util(mid, end);
    merge(start, mid, end);
}

void LinkedList::merge_sort(){
    return merge_sort_util(head_ptr, tail_ptr);    
}

void LinkedList::dump(){
    LLNode* curr = head_ptr;
    std::cout<<"\n=============================="<<std::endl;
    std::cout<<"=======LINKED LIST DUMP======="<<std::endl;
    std::cout<<"==============================\n"<<std::endl;
    std::cout<<"HEAD--";
    while (curr){
        if(curr==tail_ptr){
            std::cout<<curr->value<<"--TAIL"<<std::endl;
            curr = curr->next;
        }else{
            std::cout<<curr->value<<"->";
            curr = curr->next;
        }
    }
    std::cout<<"\n==============================\n"<<std::endl;
}