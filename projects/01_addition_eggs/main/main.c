#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// กำหนดชื่อสำหรับแสดงใน log
static const char *TAG = "EGGS_MATH";

void app_main(void)
{
    ESP_LOGI(TAG, "🥚 เริ่มต้นโปรแกรมนับไข่ไก่ของแม่ 🥚");
    ESP_LOGI(TAG, "=====================================");

    // ประกาศตัวแปรเก็บจำนวนไข่
    int eggs_already_have = 4;   // ไข่ไก่ที่แม่มีอยู่แล้ว
    int eggs_new_today = 2;      // ไข่ไก่ที่ไก่ออกวันนี้
    int total_eggs;              // ไข่ไก่ทั้งหมด

    // แสดงข้อมูลเริ่มต้น
    ESP_LOGI(TAG, "📖 โจทย์:");
    ESP_LOGI(TAG, "   แม่มีไข่ไก่อยู่แล้ว: %d ฟอง", eggs_already_have);
    ESP_LOGI(TAG, "   เมื่อเช้าไก่ออกไข่เพิ่ม: %d ฟอง", eggs_new_today);
    ESP_LOGI(TAG, "   ❓ วันนี้แม่มีไข่ไก่รวมกี่ฟอง?");
    ESP_LOGI(TAG, "");

    // รอสักครู่เพื่อให้อ่านโจทย์
    vTaskDelay(3000 / portTICK_PERIOD_MS);

    // คำนวณผลรวม (การบวก)
    total_eggs = eggs_already_have + eggs_new_today;

    // แสดงขั้นตอนการคิด
    ESP_LOGI(TAG, "🧮 ขั้นตอนการคิด:");
    ESP_LOGI(TAG, "   ไข่ไก่ที่มีอยู่ + ไข่ไก่ที่ออกใหม่");
    ESP_LOGI(TAG, "   = %d + %d", eggs_already_have, eggs_new_today);
    ESP_LOGI(TAG, "   = %d ฟอง", total_eggs);
    ESP_LOGI(TAG, "");

    // แสดงคำตอบ
    ESP_LOGI(TAG, "✅ คำตอบ:");
    ESP_LOGI(TAG, "   วันนี้แม่มีไข่ไก่ทั้งหมด %d ฟอง", total_eggs);
    ESP_LOGI(TAG, "");

    // แสดงภาพประกอบ (ASCII Art)
    ESP_LOGI(TAG, "🎨 ภาพประกอบ:");
    ESP_LOGI(TAG, "   ไข่เดิม: 🥚🥚🥚🥚 (%d ฟอง)", eggs_already_have);
    ESP_LOGI(TAG, "   ไข่ใหม่: 🥚🥚 (%d ฟอง)", eggs_new_today);
    ESP_LOGI(TAG, "   รวม:    🥚🥚🥚🥚🥚🥚 (%d ฟอง)", total_eggs);
    ESP_LOGI(TAG, "");

    // ตัวอย่างเพิ่มเติม
    ESP_LOGI(TAG, "💡 ตัวอย่างเพิ่มเติม:");

    // ตัวอย่างที่ 1
    int example1_old = 7;
    int example1_new = 3;
    int example1_total = example1_old + example1_new;
    ESP_LOGI(TAG, "   ถ้าแม่มีไข่ %d ฟอง และไก่ออกไข่ %d ฟอง", example1_old, example1_new);
    ESP_LOGI(TAG, "   จะได้ไข่ทั้งหมด %d + %d = %d ฟอง", example1_old, example1_new, example1_total);
    ESP_LOGI(TAG, "");

    // ตัวอย่างที่ 2
    int example2_old = 10;
    int example2_new = 5;
    int example2_total = example2_old + example2_new;
    ESP_LOGI(TAG, "   ถ้าแม่มีไข่ %d ฟอง และไก่ออกไข่ %d ฟอง", example2_old, example2_new);
    ESP_LOGI(TAG, "   จะได้ไข่ทั้งหมด %d + %d = %d ฟอง", example2_old, example2_new, example2_total);
    ESP_LOGI(TAG, "");

    // สรุปการเรียนรู้
    ESP_LOGI(TAG, "📚 สิ่งที่เรียนรู้:");
    ESP_LOGI(TAG, "   1. การบวกเลข (Addition): a + b = c");
    ESP_LOGI(TAG, "   2. การใช้ตัวแปร (Variables) เก็บค่า");
    ESP_LOGI(TAG, "   3. การแสดงผลด้วย ESP_LOGI");
    ESP_LOGI(TAG, "   4. การแก้โจทย์แบบมีขั้นตอน");
    ESP_LOGI(TAG, "");

    ESP_LOGI(TAG, "🎉 จบโปรแกรมนับไข่ไก่ของแม่!");
    ESP_LOGI(TAG, "📖 อ่านต่อในโปรเจคถัดไป: 02_subtraction_toys");

    // รอสักครู่ก่อนจบโปรแกรม
    vTaskDelay(2000 / portTICK_PERIOD_MS);
}
