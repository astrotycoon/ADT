#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "heapstring.h"

void err_exit(char *);
int main(int argc, char *argv[])
{
	p_heapstring_t string = NULL;
	int pos;
	char* test = "<<<<<lovevol>>>>>";
	string = heapstring_create(test);
	if (NULL == string)
		err_exit("create error");

	printf("string->ch = [%s]\n", string->ch);
	printf("string->length = %d\n", string->length);	//heapstring_create() is OK

	printf("heapstring_len(string) = %d\n", heapstring_len(string));//heapstring_len() is OK

	printf("\n--------------------------------------------------------\n");
	p_heapstring_t string_cmp = NULL;
	string_cmp = heapstring_create(test);
	printf("%d\n", heapstring_cmp(string, string_cmp));
	heapstring_destroy(string_cmp);	//heapstring_destroy() is OK
	string_cmp = heapstring_create("<<<<<lovevol>>>>>+");
	printf("%d\n", heapstring_cmp(string, string_cmp));
	printf("%d\n", heapstring_cmp(string_cmp, string));//heapstring_cmp() is OK
	
	printf("\n--------------------------------------------------------\n");


	
	printf("\n--------------------------------------------------------\n");
	//heapstring_destroy(string_cmp);
	//string_cmp = heapstring_create(test);
	printf("string_cmp->ch = [%s]\n", string_cmp->ch);
	printf("string_cmp->length = %d\n", string_cmp->length);
	printf("string->ch = [%s]\n", string->ch);
	
	p_heapstring_t dst = NULL;
	dst = heapstring_create("");
	printf("dst->ch = [%s]\n", dst->ch);
	printf("dst->length = %d\n", dst->length);

	if (heapstring_cat(dst, string, string_cmp) == true)
	{
		printf("dst->ch = [%s]\n", dst->ch);
		printf("dst->length = %d\n", dst->length);
	}
	else
		err_exit("cat error");//heapstring_cat() is OK
	printf("\n--------------------------------------------------------\n");



	printf("\n--------------------------------------------------------\n");
	printf("---------------sub---------------------------------------\n");
	p_heapstring_t sub = NULL;
	sub = heapstring_create("");
	if (NULL == sub)
		err_exit("create error");
	if (heapstring_sub(sub, dst, 1, 5) == true)
	{
		printf("sub->ch = [%s]\n", sub->ch);
		printf("sub->length = %d\n", sub->length);
	}
	else
		err_exit("sub error");	//heapstring_sub() is OK
	printf("\n--------------------------------------------------------\n");



	
	printf("\n--------------------------------------------------------\n");
	if (heapstring_empty(sub) == true)
		printf("sub is empty\n");
	else
		printf("sub is not empty\n");
	heapstring_destroy(sub);
//	if (heapstring_empty(sub) == true)
//		printf("sub is empty\n");
//	else
//		err_exit("empty error");
	sub = heapstring_create("");
	if (heapstring_empty(sub) == true)
		printf("sub is empty\n");
	else
		printf("sub is not empty\n");//heapstring_empty() is OK
	printf("\n--------------------------------------------------------\n");




	printf("\n--------------------------------------------------------\n");
	if (heapstring_cpy(sub, dst))
	{
		printf("sub->ch = [%s]\n", sub->ch);
		printf("sub->length = %d\n", sub->length);
	}
	else
		err_exit("cpy error");//heapstring_cpy() is OK
	printf("\n--------------------------------------------------------\n");


	
	printf("\n--------------------------------------------------------\n");
	heapstring_destroy(string);
	string = heapstring_create("aaabbbaaalovebbbaaabbb");
	if (NULL != string)
	{
		printf("string->ch = [%s]\n", string->ch);
		printf("string->length = %d\n", string->length);
	}
	else
		err_exit("create error");

	heapstring_destroy(string_cmp);
	string_cmp = heapstring_create("aaa");
	if (NULL != string_cmp)
	{
		printf("string_cmp->ch = [%s]\n", string_cmp->ch);
		printf("string_cmp->length = %d\n", string_cmp->length);
	}
	else
		err_exit("create error");

	pos = heapstring_index(string, string_cmp, 1);
	if (0 != pos)
		printf("pos = %d\n", pos);
	else	
		err_exit("index error");
	
	pos = heapstring_index(string, string_cmp, 11);
	if (0 != pos)
		printf("pos = %d\n", pos);
	else	
		err_exit("index error");	
	
	pos = heapstring_index(string, string_cmp, 17);
	if (0 != pos)
		printf("pos = %d\n", pos);
	else	
		err_exit("index error");	
	printf("\n--------------------------------------------------------\n");



	printf("\n--------------------------------------------------------\n");
	p_heapstring_t replace = NULL;
	replace = heapstring_create("fff");
	if (NULL != replace)
	{
		printf("replace->ch = [%s]\n", replace->ch);
		printf("replace->length = %d\n", replace->length);
	}
	else
		err_exit("create error");

	if (heapstring_replace(string, string_cmp, replace))
	{
		printf("string->ch = [%s]\n", string->ch);
		printf("string->length = %d\n", string->length);
	}
	else
		err_exit("replace error");
	printf("\n--------------------------------------------------------\n");



	
	printf("\n---------------insert---------------------------------------\n");
	p_heapstring_t src = NULL;
	src = heapstring_create("______");
	if (NULL == src)
	{
		err_exit("create error");
	}
	else
	{
		printf("src->ch = [%s]\n", src->ch);
		printf("src->length = %d\n", src->length);
	}
	if (heapstring_insert(string, 22, src))
	{
		printf("string->ch = [%s]\n", string->ch);
		printf("string->length = %d\n", string->length);
	}
	else
		err_exit("insert error");//heapstring_insert() is OK
	printf("\n--------------------------------------------------------\n");


	
	printf("\n--------------------------------------------------------\n");
	if (heapstring_delete(string, 22, 6 ))
	{
		printf("string->ch = [%s]\n", string->ch);
		printf("string->length = %d\n", string->length);
	}
	else
		err_exit("delete error");//heapstring_delete() is OK
	printf("\n--------------------------------------------------------\n");






	printf("\n--------------------------------------------------------\n");
/*	heapstring_destroy(replace);
	replace = heapstring_create("++++");
	if (NULL == replace)
		err_exit("create error");
	printf("replace->ch = [%s]\n", replace->ch);
	printf("replcae->length = %d\n", replace->length);

	heapstring_destroy(src);
	src = heapstring_create("bbb");
	if (NULL == src)
		err_exit("create error");
	printf("src->ch = [%s]\n", src->ch);
	printf("src->length = %d\n", src->length);

	printf("string->ch = [%s]\n", string->ch);	
	pos = heapstring_index(string, src, 1);
	if (0 != pos)
		printf("pos = %d\n");
	else	
		err_exit("index error");
	
	if (heapstring_replace(string, src, replace) == false)
		err_exit("replace error");

	printf("string->ch = [%s]\n", string->ch);
	printf("string->length = %d\n", string->length);*/
	printf("\n--------------------------------------------------------\n");

	heapstring_destroy(string);
	string = heapstring_create("<F2>aaaa<F2><F2>");
	if (NULL == string)
		err_exit("create error");
	printf("string->ch = [%s]\n", string->ch);
	printf("string->length = %d\n", string->length);

	heapstring_destroy(src);
	src = heapstring_create("<F2>");
	if (NULL == src)
		err_exit("create error");
	printf("src->ch = [%s]\n", src->ch);
	printf("src->length = %d\n", src->length);

	pos = heapstring_index(string, src, 1);
	if (0 != pos)
		printf("pos = %d\n", pos);
	else
		err_exit("index error");

	heapstring_destroy(replace);
	replace = heapstring_create("ff");
	if (NULL == replace)
		err_exit("create error");
	printf("replace->ch = [%s]\n", replace->ch);
	printf("replace->length = %d\n", replace->length);

	if (heapstring_replace(string, src, replace))
	{
		printf("string->ch = [%s]\n", string->ch);
		printf("string->length = %d\n", string->length);
	}
	else
		err_exit("replace error");


	printf("\n&&&&&&&&&&&&&&&&&&&&delete&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
	heapstring_destroy(string);
	string = heapstring_create("jjjkkklll<F2>dddrrrtttppp");
	if (NULL == string)
		err_exit("create error");
	printf("string->ch = [%s]\n", string->ch);
	printf("string->length = %d\n", string->length);

	if (heapstring_delete(string, 20, 6) == false)
		err_exit("delete error");

	printf("string->ch = [%s]\n", string->ch);
	printf("string->length = %d\n", string->length);
	
	printf("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
	heapstring_destroy(string);
	heapstring_destroy(string_cmp);
	heapstring_destroy(dst);
	heapstring_destroy(sub);
	heapstring_destroy(replace);
	heapstring_destroy(src);
	exit(EXIT_SUCCESS);
}

void err_exit(char* err_str)
{
	perror(err_str);
	exit(EXIT_FAILURE);
}
