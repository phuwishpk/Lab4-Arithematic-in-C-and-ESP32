#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "CANDY_PROJECT";

// แสดงภาพถุงลูกอมตามจำนวน
void show_candy_bags(int bags, int per_bag) {
    for (int i = 1; i <= bags; i++) {
        ESP_LOGI(TAG, "   ถุงที่ %d: ", i);
        printf("      ");
        for (int j = 0; j < per_bag; j++) {
            printf("🍬");
        }
        printf(" (%d เม็ด)\n", per_bag);
    }
}

// แสดงตารางสูตรคูณ
void show_multiplication_table(int base) {
    ESP_LOGI(TAG, "📊 ตารางสูตรคูณของ %d:", base);
    for (int i = 1; i <= 10; i++) {
        ESP_LOGI(TAG, "   %d × %d = %d", i, base, i * base);
        vTaskDelay(300 / portTICK_PERIOD_MS);
    }
}

// แสดงการบวกซ้ำๆ
void show_repeated_addition(int times, int value) {
    ESP_LOGI(TAG, "🔄 การบวกซ้ำๆ:");
    int sum = 0;
    for (int i = 0; i < times; i++) {
        sum += value;
        if (i == 0) {
            printf("      %d", value);
        } else {
            printf(" + %d", value);
        }
    }
    printf(" = %d\n", sum);
}

// แจกจ่ายลูกอมให้เพื่อน
void share_candies(int total, int friends) {
    int per_friend = total / friends;
    int leftover = total % friends;
    ESP_LOGI(TAG, "👥 แจกให้เพื่อน %d คน:", friends);
    ESP_LOGI(TAG, "   คนละ %d เม็ด", per_friend);
    ESP_LOGI(TAG, "   เหลือ %d เม็ด", leftover);
}

void app_main(void)
{
    // ตั้งค่าข้อมูลเริ่มต้น
    int candies_per_bag = 6;
    int strawberry_bags = 3;
    int orange_bags = 2;
    int grape_bags = 4;

    // คำนวณรวม
    int total_bags = strawberry_bags + orange_bags + grape_bags;
    int total_candies = total_bags * candies_per_bag;

    ESP_LOGI(TAG, "🍬 เริ่มต้นโปรแกรมนับลูกอม 🍬");
    ESP_LOGI(TAG, "=======================================");
    ESP_LOGI(TAG, "📦 ถุงลูกอมรวมทั้งหมด %d ถุง (รสต่างๆ)", total_bags);
    ESP_LOGI(TAG, "   - 🍓 สตรอเบอร์รี่: %d ถุง", strawberry_bags);
    ESP_LOGI(TAG, "   - 🍊 รสส้ม: %d ถุง", orange_bags);
    ESP_LOGI(TAG, "   - 🍇 รสองุ่น: %d ถุง", grape_bags);
    ESP_LOGI(TAG, "📌 ลูกอมถุงละ: %d เม็ด", candies_per_bag);
    ESP_LOGI(TAG, "🧮 รวมลูกอมทั้งหมด: %d × %d = %d เม็ด",
             total_bags, candies_per_bag, total_candies);
    ESP_LOGI(TAG, "");

    // แสดงภาพถุงลูกอม
    show_candy_bags(total_bags, candies_per_bag);

    // แสดงการบวกซ้ำๆ
    show_repeated_addition(total_bags, candies_per_bag);

    // ตารางสูตรคูณ
    show_multiplication_table(candies_per_bag);

    // แจกจ่ายลูกอมให้เพื่อน
    share_candies(total_candies, 12);

    // ความรู้เสริม
    ESP_LOGI(TAG, "");
    ESP_LOGI(TAG, "🎓 ความรู้เพิ่มเติม:");
    ESP_LOGI(TAG, "   ✅ การคูณคือการบวกซ้ำๆ");
    ESP_LOGI(TAG, "   ✅ การหาร: %d ÷ 12 = %d (เศษ %d)", 
             total_candies, total_candies / 12, total_candies % 12);
    ESP_LOGI(TAG, "   ✅ การคูณมีคุณสมบัติสับเปลี่ยน: a × b = b × a");

    ESP_LOGI(TAG, "");
    ESP_LOGI(TAG, "🎉 จบโปรแกรมนับลูกอม!");
}
