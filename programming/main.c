#include <stdio.h>
#include <windows.h>

int balance = 0;
int history[100];
int count = 0;

void deposit()
{
    int money;

    printf("입금할 금액: ");
    if (scanf_s("%d", &money) != 1)
    {
        printf("숫자를 입력해주세요.\n");
        return;
    }

    if (money <= 0)
    {
        printf("올바른 금액을 입력해주세요.\n");
        return;
    }

    if (count >= 100 || money > 2147483647 - balance)
    {
        printf("입금할 수 없습니다.\n");
        return;
    }

    balance += money;
    history[count] = money;
    count++;

    printf("%d원 입금 완료!\n", money);
}

void withdraw()
{
    int money;

    printf("출금할 금액: ");
    if (scanf_s("%d", &money) != 1)
    {
        printf("숫자를 입력해주세요.\n");
        return;
    }

    if (money <= 0)
    {
        printf("올바른 금액을 입력해주세요.\n");
    }
    else if (money > balance)
    {
        printf("잔액이 부족합니다.\n");
    }
    else if (count >= 100)
    {
        printf("거래 내역이 가득 찼습니다.\n");
    }
    else
    {
        balance -= money;
        history[count] = -money;
        count++;

        printf("%d원 출금 완료!\n", money);
    }
}

void showBalance()
{
    printf("현재 잔액: %d원\n", balance);
}

void showHistory()
{
    int i;

    if (count == 0)
    {
        printf("거래 내역이 없습니다.\n");
        return;
    }

    printf("\n===== 거래 내역 =====\n");

    for (i = 0; i < count; i++)
    {
        if (history[i] > 0)
        {
            printf("%d. 입금: %d원\n", i + 1, history[i]);
        }
        else
        {
            printf("%d. 출금: %d원\n", i + 1, -history[i]);
        }
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    int menu;

    while (1)
    {
        printf("\n===== ATM 은행 관리 =====\n");
        printf("1. 입금\n");
        printf("2. 출금\n");
        printf("3. 잔액 조회\n");
        printf("4. 거래 내역 조회\n");
        printf("0. 종료\n");
        printf("=========================\n");
        printf("메뉴 선택: ");

        if (scanf_s("%d", &menu) != 1)
        {
            printf("숫자만 입력해주세요.\n");
            break;
        }

        switch (menu)
        {
        case 1:
            deposit();
            break;
        case 2:
            withdraw();
            break;
        case 3:
            showBalance();
            break;
        case 4:
            showHistory();
            break;
        case 0:
            printf("프로그램을 종료합니다.\n");
            return 0;
        default:
            printf("잘못된 메뉴입니다.\n");
        }
    }

    return 0;
}