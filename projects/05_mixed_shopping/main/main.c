#include <stdio.h>
#include <string.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "SHOPPING_MATH";

typedef struct {
    char name[20];
    int quantity;
    float price_per_unit;
    float total_price;
} product_t;

void calculate_product_total(product_t *product) {
    product->total_price = product->quantity * product->price_per_unit;
}

void display_product(const product_t *product) {
    ESP_LOGI(TAG, "   %s: %d × %.0f = %.0f บาท",
             product->name, product->quantity, product->price_per_unit, product->total_price);
}

float calculate_total_bill(product_t products[], int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        calculate_product_total(&products[i]);
        total += products[i].total_price;
    }
    return total;
}

float apply_discount(float total, float discount) {
    return total - discount;
}

float add_vat(float total, float vat_percent) {
    return total + (total * vat_percent / 100.0);
}

float split_payment(float amount, int people) {
    if (people <= 0) {
        ESP_LOGE(TAG, "Error: จำนวนคนต้องมากกว่า 0");
        return 0.0;
    }
    return amount / people;
}

void app_main(void)
{
    ESP_LOGI(TAG, "🛒 เริ่มต้นโปรแกรมซื้อของที่ตลาด 🛒");
    ESP_LOGI(TAG, "=====================================");

    product_t products[] = {
        {"แอปเปิ้ล", 6, 15.0, 0.0},
        {"กล้วย", 12, 8.0, 0.0},
        {"ส้ม", 8, 12.0, 0.0}
    };
    int product_count = sizeof(products) / sizeof(products[0]);
    float discount = 20.0;
    float vat_percent = 7.0;
    int people = 3;

    ESP_LOGI(TAG, "\n📖 โจทย์:");
    for (int i = 0; i < product_count; i++) {
        ESP_LOGI(TAG, "   - %s: %d หน่วย หน่วยละ %.0f บาท",
                 products[i].name, products[i].quantity, products[i].price_per_unit);
    }
    ESP_LOGI(TAG, "   - ส่วนลด: %.0f บาท", discount);
    ESP_LOGI(TAG, "   - ภาษี VAT: %.0f%%", vat_percent);
    ESP_LOGI(TAG, "   - แบ่งจ่าย: %d คน", people);

    vTaskDelay(2000 / portTICK_PERIOD_MS);

    float subtotal = calculate_total_bill(products, product_count);
    float discounted_total = apply_discount(subtotal, discount);
    float total_with_vat = add_vat(discounted_total, vat_percent);
    float per_person = split_payment(total_with_vat, people);

    ESP_LOGI(TAG, "\n🧾 ใบเสร็จซื้อของที่ตลาด");
    ESP_LOGI(TAG, "   ==========================================");
    for (int i = 0; i < product_count; i++) {
        display_product(&products[i]);
    }
    ESP_LOGI(TAG, "   ------------------------------------------");
    ESP_LOGI(TAG, "   รวม:                     %.2f บาท", subtotal);
    ESP_LOGI(TAG, "   ส่วนลด:                 -%.2f บาท", discount);
    ESP_LOGI(TAG, "   ยอดหลังหักส่วนลด:       %.2f บาท", discounted_total);
    ESP_LOGI(TAG, "   VAT %.0f%%:                +%.2f บาท", vat_percent, total_with_vat - discounted_total);
    ESP_LOGI(TAG, "   ==========================================");
    ESP_LOGI(TAG, "   ยอดสุทธิ:               %.2f บาท", total_with_vat);
    ESP_LOGI(TAG, "   แบ่งจ่าย %d คน:           %.2f บาท/คน", people, per_person);
    ESP_LOGI(TAG, "   ==========================================");
    ESP_LOGI(TAG, "   ขอบคุณที่ใช้บริการ ❤️");

    // สรุปการเรียนรู้
    ESP_LOGI(TAG, "\n📚 สิ่งที่เรียนรู้:");
    ESP_LOGI(TAG, "   ✓ การคูณ (×): คำนวณราคาสินค้าแต่ละชนิด");
    ESP_LOGI(TAG, "   ✓ การบวก (+): รวมราคาทั้งหมด");
    ESP_LOGI(TAG, "   ✓ การลบ (-): หักส่วนลด");
    ESP_LOGI(TAG, "   ✓ การหาร (÷): แบ่งจ่ายค่าใช้จ่าย");
    ESP_LOGI(TAG, "   ✓ การเพิ่มภาษี (VAT)");
    ESP_LOGI(TAG, "   ✓ การใช้ struct และ function ใน C");
    ESP_LOGI(TAG, "   ➜ รวมการดำเนินการเพื่อแก้ปัญหาจริงในชีวิต!");
}
