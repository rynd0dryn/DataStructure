//legnth 안쓰고
//bool NStack::nmPush(int n, int m, string input)
//{
//    ItemType *newItem;
//    ItemType *ptr;
//    ItemType *tempPtr;
//    newItem = new ItemType;
//    newItem->item = input;
//    newItem->next = nullptr;
//    newItem->back = nullptr;
//
//    ptr = data;
//
//    if(data == nullptr) //초기 추가
//    {
//        data = newItem;
//        return true;
//    }
//
//    for(int i=0; i<n; i++)
//    {
//        if(ptr == nullptr)
//        {
//            return false;
//        }
//        tempPtr = ptr;
//        ptr = ptr->next;
//    }
//
//    for(int i=0; i<m; i++)
//    {
//        if(ptr == nullptr)
//        {
//            return false;
//        }
//        tempPtr = ptr;
//        ptr = ptr->back;
//    }
//
//    if(ptr == nullptr)  // 앞 혹은 뒤가 null case
//    {
//        if(tempPtr->next == nullptr)
//        {
//            newItem->back = tempPtr;
//            tempPtr->next = newItem;
//        }
//        if(tempPtr->back == nullptr)
//        {
//            newItem->next = tempPtr;
//            tempPtr->back = newItem;
//            data = newItem;
//        }
//    }
//    else //앞 뒤가 null case x
//    {
//        if(ptr->back == nullptr) //이동 x
//        {
//            newItem->next = ptr;
//            ptr->back = newItem;
//            data = newItem;
//        }
//        else //general
//        {
//            newItem->next = ptr;
//            newItem->back = ptr->back;
//            ptr->back->next = newItem;
//            ptr->back = newItem;
//        }
//    }
//    return true;
//}

//bool NStack::nmPop(int n, int m, string& output)
//{
//    ItemType *ptr;
//    ptr = data;
//
//
//
//    if(data == nullptr)
//        return false;
//
//    for(int i=0; i<n; i++)
//    {
//        ptr = ptr->next;
//        if(ptr == nullptr) {
//            return false;
//        }
//    }
//
//    for(int i=0; i<m; i++)
//    {
//        ptr = ptr->back;
//        if(ptr == nullptr)
//        {
//            return false;
//        }
//    }
//
//    if(ptr->back == nullptr)
//    {
//        output = ptr->item;
//        data = ptr->next;
//        ptr->next = nullptr;
//        delete ptr;
//    }
//    else if(ptr->next == nullptr)
//    {
//        output = ptr->item;
//        ptr->back->next = nullptr;
//        delete ptr;
//    }
//    else
//    {
//        output = ptr->item;
//        ptr->back->next = ptr->next;
//        ptr->next->back = ptr->back;
//        delete ptr;
//    }
//    return true;
//}