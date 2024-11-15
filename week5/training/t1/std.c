#include <stdio.h>
#include <string.h>

#define CARDS_IN_HAND 5

// 定义牌面点数映射到整数的数组
int rank_to_int(char rank) {
    switch (rank) {
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        case 'T': return 10;
        case 'J': return 11;
        case 'Q': return 12;
        case 'K': return 13;
        case 'A': return 14;
        default: return 0;
    }
}

// 判断牌型并输出结果
void evaluate_hand(int hand[CARDS_IN_HAND]) {
    int rank_counts[15] = {0}; // 从2到A的计数数组
    int i, rank, is_straight = 0, pairs = 0, three_of_a_kind = 0, four_of_a_kind = 0;

    // 计算每个点数的牌的数量
    for (i = 0; i < CARDS_IN_HAND; i++) {
        rank_counts[hand[i]]++;
    }

    // 检查顺子
    rank_counts[1] = rank_counts[14];
    for(int i=14;i>=5;i--){
        int ok = 1;
        for(int j=0;j<=4;j++){
            if(rank_counts[i-j] == 0) ok = 0;
        }
        is_straight |= ok;
    }
    if (is_straight) {
        printf("Flush\n");
        return;
    }

    // 检查四条、葫芦、三条、两对、一对
    for (i = 2; i <= 14; i++) {
        if (rank_counts[i] == 4) {
            four_of_a_kind = 1;
        } else if (rank_counts[i] == 3) {
            three_of_a_kind++;
        } else if (rank_counts[i] == 2) {
            pairs++;
        }
    }

    if (four_of_a_kind) {
        printf("Four of a Kind\n");
    } else if (three_of_a_kind == 1 && pairs == 1) {
        printf("Full House\n");
    } else if (three_of_a_kind == 1) {
        printf("Three of a Kind\n");
    } else if (pairs == 2) {
        printf("Two Pairs\n");
    } else if (pairs == 1) {
        printf("One Pair\n");
    } else {
        printf("High Card\n");
    }
}

int main() {
    int t, i;
    char rank;
    int hand[CARDS_IN_HAND];

    scanf("%d", &t); // 读取测试用例的数量

    while (t--) {
        for (i = 0; i < CARDS_IN_HAND; i++) {
            scanf(" %c", &rank); // 读取牌面点数
            hand[i] = rank_to_int(rank); // 转换为整数
        }
        evaluate_hand(hand); // 判断牌型并输出结果
    }

    return 0;
}
