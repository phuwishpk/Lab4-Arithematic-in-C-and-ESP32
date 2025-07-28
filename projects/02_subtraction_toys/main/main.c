#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// เปลี่ยนชื่อ TAG ให้สื่อความหมายมากขึ้น
static const char *TAG = "TOYS_CHALLENGE";

void app_main(void)
{
    ESP_LOGI(TAG, "🧸 โปรแกรมตะลุยโจทย์ของเล่นของน้อง 🧸");
    ESP_LOGI(TAG, "========================================");

    // --- เริ่ม: แก้ไขแบบฝึกหัดที่ 1 ---
    // เปลี่ยนจำนวนของเล่นตามโจทย์
    int toys_at_home = 15;      // ของเล่นที่บ้าน (เดิม 8)
    int toys_give_away = 7;     // ของเล่นที่แจก (เดิม 3)
    int toys_remaining;         // ของเล่นที่เหลือ
    // --- จบ: แก้ไขแบบฝึกหัดที่ 1 ---

    ESP_LOGI(TAG, "📖 โจทย์หลัก:");
    ESP_LOGI(TAG, "   น้องมีของเล่น: %d ชิ้น", toys_at_home);
    ESP_LOGI(TAG, "   เอาไปแจกให้เพื่อน: %d ชิ้น", toys_give_away);
    ESP_LOGI(TAG, "");

    vTaskDelay(2000 / portTICK_PERIOD_MS);

    // --- เริ่ม: แก้ไขแบบฝึกหัดที่ 2 ---
    // เพิ่มการตรวจสอบว่าของเล่นพอแจกหรือไม่
    ESP_LOGI(TAG, "🔍 ตรวจสอบก่อนแจก:");
    if (toys_at_home >= toys_give_away) {
        ESP_LOGI(TAG, "   ✅ ของเล่นพอแจก");
        // คำนวณผลลัพธ์ (การลบ)
        toys_remaining = toys_at_home - toys_give_away;
        ESP_LOGI(TAG, "   เหลือของเล่น %d - %d = %d ชิ้น", 
                 toys_at_home, toys_give_away, toys_remaining);

    } else {
        ESP_LOGI(TAG, "   ❌ ของเล่นไม่พอ! ขาดไป %d ชิ้น", 
                 toys_give_away - toys_at_home);
        // เมื่อของไม่พอแจก จะถือว่าเหลือเท่าเดิม
        toys_remaining = toys_at_home; 
        ESP_LOGW(TAG, "   ไม่สามารถแจกได้ น้องจึงเหลือของเล่น %d ชิ้นเท่าเดิม", toys_remaining);
    }
    ESP_LOGI(TAG, "");
    // --- จบ: แก้ไขแบบฝึกหัดที่ 2 ---

    vTaskDelay(2000 / portTICK_PERIOD_MS);

    // --- เริ่ม: แก้ไขแบบฝึกหัดที่ 3 ---
    // เพิ่มของเล่นประเภทอื่นและคำนวณผลรวม
    ESP_LOGI(TAG, "🧩 เพิ่มของเล่นประเภทอื่น:");
    int dolls = 5;      // ตุ๊กตา
    int robots = 2;     // หุ่นยนต์
    int total_toys = toys_at_home + dolls + robots; // ใช้ค่า toys_at_home ที่มีอยู่

    ESP_LOGI(TAG, "   🪆 ตุ๊กตา: %d ตัว", dolls);
    ESP_LOGI(TAG, "   🤖 หุ่นยนต์: %d ตัว", robots);
    ESP_LOGI(TAG, "   🎯 รวมของเล่นทุกชนิดที่มีตอนนี้: %d + %d + %d = %d ชิ้น",
             toys_at_home, dolls, robots, total_toys);
    ESP_LOGI(TAG, "");
    // --- จบ: แก้ไขแบบฝึกหัดที่ 3 ---

    vTaskDelay(2000 / portTICK_PERIOD_MS);

    // --- เริ่ม: แก้ไขแบบฝึกหัดที่ 4 ---
    // คำนวณโจทย์ปัญหาให้คิด
    ESP_LOGI(TAG, "🤔 โจทย์ให้คิด:");
    ESP_LOGI(TAG, "   หากน้องอยากแจกของเล่นให้เพื่อน 10 คน คนละ 2 ชิ้น...");
    
    int friends = 10;
    int toys_per_friend = 2;
    int toys_needed = friends * toys_per_friend;
    int toys_available = 15; // จากโจทย์ที่ว่า "ถ้ามี 15 ชิ้น"
    
    ESP_LOGI(TAG, "   1. ต้องมีของเล่นทั้งหมด: %d x %d = %d ชิ้น", 
             friends, toys_per_friend, toys_needed);

    if (toys_available < toys_needed) {
        int toys_shortage = toys_needed - toys_available;
        ESP_LOGI(TAG, "   2. ถ้ามี %d ชิ้น จะขาดอีก: %d - %d = %d ชิ้น",
                 toys_available, toys_needed, toys_available, toys_shortage);
    } else {
        ESP_LOGI(TAG, "   2. ถ้ามี %d ชิ้น ของเล่นจะพอดีหรือพอสำหรับแจก", toys_available);
    }
    ESP_LOGI(TAG, "");
    // --- จบ: แก้ไขแบบฝึกหัดที่ 4 ---

    ESP_LOGI(TAG, "🎉 จบโปรแกรมตะลุยโจทย์!");
}
