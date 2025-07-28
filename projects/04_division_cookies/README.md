#include <stdio.h>
#include <stdlib.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "COOKIES_MATH";

void app_main(void)
{
    ESP_LOGI(TAG, "🍪 เริ่มต้นโปรแกรมแบ่งคุกกี้ 🍪");
    ESP_LOGI(TAG, "================================");

    // 🔢 ประกาศตัวแปรเริ่มต้น
    int total_cookies = 12;        // คุกกี้ทั้งหมด
    int number_of_friends = 4;     // จำนวนเพื่อน
    int cookies_per_person = 0;
    int remaining_cookies = 0;

    // 📖 แสดงโจทย์
    ESP_LOGI(TAG, "📖 โจทย์:");
    ESP_LOGI(TAG, "   มีคุกกี้: %d ชิ้น", total_cookies);
    ESP_LOGI(TAG, "   จะแบ่งให้เพื่อน: %d คน", number_of_friends);
    ESP_LOGI(TAG, "   ❓ แต่ละคนได้คุกกี้กี่ชิ้น?");
    ESP_LOGI(TAG, "");

    vTaskDelay(2000 / portTICK_PERIOD_MS);

    // ❌ ตรวจสอบหารด้วยศูนย์
    if (number_of_friends == 0) {
        ESP_LOGE(TAG, "❌ ข้อผิดพลาด: ไม่สามารถหารด้วยศูนย์ได้!");
        ESP_LOGI(TAG, "   คุกกี้ทั้งหมดจะเหลือไว้ทั้งหมด: %d ชิ้น", total_cookies);
        ESP_LOGI(TAG, "🎉 จบโปรแกรม");
        return;
    }

    // ✅ คำนวณผลลัพธ์
    cookies_per_person = total_cookies / number_of_friends;
    remaining_cookies = total_cookies % number_of_friends;

    ESP_LOGI(TAG, "🧮 ขั้นตอนการคิด:");
    ESP_LOGI(TAG, "   %d ÷ %d = %d ชิ้นต่อคน", total_cookies, number_of_friends, cookies_per_person);
    ESP_LOGI(TAG, "   เศษที่เหลือ = %d", remaining_cookies);
    ESP_LOGI(TAG, "");

    // ✅ แสดงคำตอบ
    ESP_LOGI(TAG, "✅ คำตอบ:");
    ESP_LOGI(TAG, "   แต่ละคนได้: %d ชิ้น", cookies_per_person);
    if (remaining_cookies > 0) {
        ESP_LOGI(TAG, "   เหลือ: %d ชิ้น", remaining_cookies);
    } else {
        ESP_LOGI(TAG, "   แบ่งได้พอดี ไม่มีเหลือ");
    }
    ESP_LOGI(TAG, "");

    // 🎨 แสดงภาพประกอบการแบ่ง
    ESP_LOGI(TAG, "🎨 ภาพประกอบ:");
    ESP_LOGI(TAG, "   คุกกี้ทั้งหมด:");
    for (int i = 0; i < total_cookies; i++) {
        printf("🍪");
        if ((i + 1) % 6 == 0) printf("\n"); // จัดบรรทัดใหม่ทุก 6 ชิ้น
    }
    printf("\n\n");

    // ➗ แสดงการแบ่งให้แต่ละคน
    for (int i = 1; i <= number_of_friends; i++) {
        ESP_LOGI(TAG, "   เพื่อนคนที่ %d ได้: ", i);
        for (int j = 0; j < cookies_per_person; j++) {
            printf("🍪");
        }
        printf(" (%d ชิ้น)\n", cookies_per_person);
    }

    // 🍪 แสดงคุกกี้ที่เหลือ
    if (remaining_cookies > 0) {
        ESP_LOGI(TAG, "   คุกกี้ที่เหลือ: ");
        for (int i = 0; i < remaining_cookies; i++) {
            printf("🍪");
        }
        printf(" (%d ชิ้น)\n", remaining_cookies);
    }

    ESP_LOGI(TAG, "");

    // 🧪 ตัวอย่างเพิ่มเติม
    ESP_LOGI(TAG, "💡 ตัวอย่างเพิ่มเติม:");

    // 🔹 ตัวอย่างที่ 1
    int ex1_cookies = 15, ex1_friends = 3;
    ESP_LOGI(TAG, "   %d ÷ %d = %d เหลือ %d", 
        ex1_cookies, ex1_friends, ex1_cookies / ex1_friends, ex1_cookies % ex1_friends);

    // 🔹 ตัวอย่างที่ 2
    int ex2_cookies = 13, ex2_friends = 4;
    ESP_LOGI(TAG, "   %d ÷ %d = %d เหลือ %d", 
        ex2_cookies, ex2_friends, ex2_cookies / ex2_friends, ex2_cookies % ex2_friends);

    // 🔹 กรณีพิเศษ
    ESP_LOGI(TAG, "⚠️  กรณีพิเศษ: แบ่งให้ 0 คน → หารไม่ได้");

    // 🔁 ความสัมพันธ์กับการคูณ
    ESP_LOGI(TAG, "🔄 การคูณกลับ:");
    ESP_LOGI(TAG, "   %d × %d = %d", cookies_per_person, number_of_friends, cookies_per_person * number_of_friends);
    if (remaining_cookies > 0) {
        ESP_LOGI(TAG, "   บวกเศษ: %d + %d = %d", cookies_per_person * number_of_friends, remaining_cookies, total_cookies);
    }

    // 📚 สรุปการเรียนรู้
    ESP_LOGI(TAG, "📚 สรุป:_
