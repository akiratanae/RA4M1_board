# Simple Interrupt Software
## 概要
RA4M1のタイマ(AGT)を使用したLED点滅ソフトウェア
## e2studioでの手順
1. 新規Renesas C/C++ projectでプロジェクト作成(device=R7FA4M1AB3CFM)
2. ConfigurationのClockでクロック確認(XTAL=12MHz, ICLK=48MHzなど)
3. ConfigurationのPinでLED端子(P303,P304,P113)を出力に設定
4. ConfigurationのInterruptsでAGT0 INTイベントにISRを追加
5. Generate Project Contentボタンでコード生成
6. ra_gen/main.cをビルド対象から外す
7. srcにmain.cを追加、編集。タイマ割込みハンドラ名は4で指定したISR名
8. プロジェクトのビルド
## 備考
- IRQ(16番目から)のベクタテーブルは、ConfigurationでISR登録するとra_gen\vector_data.cに順番に作成される