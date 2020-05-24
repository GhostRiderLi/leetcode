class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def creatList(lst:list) ->ListNode:
    ret = ListNode(0)
    result = ret
    for index in range(len(lst)):
        ret.next = ListNode(lst[index])
        ret = ret.next

    return result.next

def printListNode(lst:ListNode):
    while lst is not None:
        end = ',' if lst.next is not None else '\n'
        print(str(lst.val), end = end)
        
        lst = lst.next

def addTwoNumbers(l1: ListNode, l2: ListNode) -> ListNode:
    carry = 0
    summ = 0
    ret = ListNode(0)
    result = ret
    while l1 or l2 or (carry != 0) :
        # print('l1 is not None' if l1  else 'l1 is None')
        # print("l2 is not None" if l2  else 'l2 is None')
        # print("carry not equals 0" if carry != 0 else 'carry equals 0')
        summ = (l1.val if l1 else 0) + (l2.val if l2 else 0) + carry
        print(summ)
        carry = summ // 10
        ret.next =ListNode(summ % 10)

        ret = ret.next
        l1 = l1.next if l1 else 0
        l2 = l2.next if l2 else 0
    return result.next



if __name__ == '__main__':
    # addTwoNumbers
    l1 = creatList([2,4,3])
    l2 = creatList([5,6,4])
    printListNode(l1)
    printListNode(l2)
    printListNode(addTwoNumbers(l1, l2))
