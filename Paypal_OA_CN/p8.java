class SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode next;
    SinglyLinkedListNode(int data) {
        this.data = data;
        this.next = null;
    }
}

public class p8 {
    public static SinglyLinkedListNode deleteEven(SinglyLinkedListNode listHead) {
        SinglyLinkedListNode cur = listHead;
        SinglyLinkedListNode pre = null;
        while (cur != null) {
            if (cur.data % 2 == 0) {
                if (pre == null) {
                    listHead = cur.next;
                } else {
                    pre.next = cur.next;
                }
                cur = cur.next;
            } else {
                pre = cur;
                cur = cur.next;
            }
        }
        return listHead;
    }

    public static void main(String[] args) {
        SinglyLinkedListNode head = new SinglyLinkedListNode(1);
        head.next = new SinglyLinkedListNode(2);
        head.next.next = new SinglyLinkedListNode(3);
        head.next.next.next = new SinglyLinkedListNode(4);
        head.next.next.next.next = new SinglyLinkedListNode(5);
        head.next.next.next.next.next = new SinglyLinkedListNode(6);
        head.next.next.next.next.next.next = new SinglyLinkedListNode(7);
        head.next.next.next.next.next.next.next = new SinglyLinkedListNode(8);
        SinglyLinkedListNode res = deleteEven(head);
        while (res != null) {
            System.out.println(res.data);
            res = res.next;
        }
    }
}