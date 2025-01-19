

template<class elemType>
class sLinkList :public list<elemType> {
	private:

		struct node {
			elemType data;
			node* next;

			node(const elemType& x, node* n = nullptr) {
				data = x;
				next = n;
			}

			node() :next(nullptr) {}

			~node() {}
		};

		node* head;
		int currentLength;

		node* move(int i)const; //���ص�i�����ĵ�ַ

	public:
		sLinkList();
		~sLinkList();
		void clear();
		int length()const;
		void insert(int i, const elemType& x)const;
		void remove(int i);
		int search(const elemType& x)const;
		elemType visit(int i)const;
		void traverse()const;
};