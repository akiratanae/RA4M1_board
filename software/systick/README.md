# First Software
## 概要
CortexM4のSysTickタイマを使用したLED点滅ソフトウェア
## e2studioでの手順
1. 新規Renesas C/C++ projectでプロジェクト作成(device=R7FA4M1AB3CFM)
2. ConfigurationのClockでクロック確認(XTAL=12MHz, ICLK=48MHzなど)
3. ConfigurationのPinでLED端子(P303,P304,P113)を出力に設定
4. Generate Project Contentボタンでコード生成
5. ra_gen/main.cをビルド対象から外す
6. srcにmain.cを追加、編集
7. プロジェクトのビルド
## 備考
- 0番地からSysTick(15番目)までのベクタテーブルは、startup.cで設置されている