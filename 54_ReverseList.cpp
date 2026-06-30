struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * 逆置带头结点的单链表
 * @param L 带头结点的单链表的头指针（注意：传入的是头结点的指针，不是首元结点）
 */
void ReverseList(ListNode *L)
{
    // 1. 边界条件处理：如果链表为空，或者只有一个头结点（没有数据结点），则无需逆置
    if (L == nullptr || L->next == nullptr)
        return;

    // 2. p 指向第一个数据结点，r 作为辅助指针暂存后继结点
    ListNode *p = L->next, *r;

    // 3. 断开头结点与原数据结点的联系，构造一个初始为空的带头结点链表
    L->next = nullptr;

    // 4. 遍历原数据结点链表，依次头插到 L 后面
    while (p != nullptr)
    {
        r = p->next;       // 暂存 p 的下一个结点，防止断链后找不到
        p->next = L->next; // 将 p 结点插入到头结点 L 的后面
        L->next = p;       // 头结点 L 的 next 指向新插入的 p 结点
        p = r;             // p 移动到下一个待处理的结点
    }
}