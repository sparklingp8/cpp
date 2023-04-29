node *revList(node *h)
{
    node *prev, *cur, *nxt = NULL;

    prev = h;
    cur = prev->next;
    if (listSize(h) > 2)
    {
        nxt = cur->next;
        prev->next = NULL;
        while (nxt->next != NULL)
        {
            prev = cur;
            cur = nxt;
            nxt = nxt->next;
        }
        nxt->next = cur;
        cur->next = prev;
        h = nxt;
    }
    else
    {
        prev->next = NULL;
        cur->next = prev;
        h = cur;
        cout << "hsere" << prev;
    }

    cout << "\n-----------------------------------\n";
    cout << " List reversed  ";
    cout << "\n-----------------------------------";
    seeList(h);

    return h;
}
