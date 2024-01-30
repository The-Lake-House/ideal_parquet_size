# ideal-parquet-size

Collection of experiments to find the ideal size of Parquet files in Trino:

- `footer_length`: How large can Parquet files be to make use of the 48 KiB
  footer retrieval heuristic in Trino?
